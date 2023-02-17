/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:25:19 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 21:48:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @file terminal.c
 * @brief コマンド入力の待機状態。
 * @date 2023-01-01
 */

#include "terminal.h"
#include "constant.h"
#include "parser.h"
#include "expansion.h"
#include "execution.h"
#include <readline/readline.h>
#include <readline/history.h>

/** 最後のコマンドの終了ステータスを保持する */
int	g_status = 0;

static void	delete_token(void *p_token, void *p_item)
{
	t_token	*token;

	(void)p_item;
	token = (t_token *)p_token;
	free(token->data);
}

/**
 * @brief 入力・字句解析・構文解析に使用したメモリを解放する。

 * @param line 入力された文字列
 * @param lexed_tokens　字句解析により生成されたトークン
 * @param syntax_tree　構文解析により生成された抽象構文木
 */
static void	free_buffers(char *line, t_vector *tokens, t_ast_node *tree)
{
	ft_vector_foreach(tokens, delete_token, NULL);
	ft_vector_delete(&tokens);
	ast_node_delete(tree);
	free(line);
}

/**
 * @brief 標準入力を待機し、コマンドの字句・構文解析および実行を行う。
 *
 * @param msh　シェルの管理情報
 */
void	terminal(t_shell	*msh)
{
	char		*line;
	t_vector	*lexed_tokens;
	t_ast_node	*syntax_tree;

	set_ignore_signal();
	line = NULL;
	while (true)
	{
		line = readline(msh->prompt);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		lexer(line, &lexed_tokens);
		parser(lexed_tokens, &syntax_tree, msh);
		expander(syntax_tree, msh);
		executor(syntax_tree, msh);
		free_buffers(line, lexed_tokens, syntax_tree);
	}
	exit(EXIT_FAILURE);
}

/**
 * @brief コマンド入力の待機（デバッグ用）
 *
 * @param msh　シェルの管理情報
 */
void	terminal_dev(t_shell	*msh)
{
	char		*line;
	t_vector	*lexed_tokens;
	t_ast_node	*syntax_tree;

	set_ignore_signal();
	line = NULL;
	while (true)
	{
		line = readline(msh->prompt);
		if (!line)
			break ;
		else if (*line)
			add_history(line);
		print_input(line);
		lexer(line, &lexed_tokens);
		print_tokens(lexed_tokens);
		parser(lexed_tokens, &syntax_tree, msh);
		print_nodes(syntax_tree);
		expander(syntax_tree, msh);
		print_commands(syntax_tree);
		print_output();
		executor(syntax_tree, msh);
		free_buffers(line, lexed_tokens, syntax_tree);
	}
	exit(EXIT_FAILURE);
}
