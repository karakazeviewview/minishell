/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:33:48 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:40:00 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libast.h"

/**
 * @brief コマンドの引数をすべて走査し、 単語の展開を試みる。
 *
 * @param command
 * @param environ
 */
static void	expand_arguments(t_argument *arguments, t_hashmap *environ)
{
	t_argument	*curr;
	char		*buff;

	curr = arguments;
	while (curr)
	{
		if (curr->type & NODE_WORD)
		{
			buff = NULL;
			ft_wordexp(curr->argument, &buff, environ);
			free(curr->argument);
			if (buff)
				curr->argument = ft_strdup(buff);
			else
				curr->argument = ft_strdup("");
			free(buff);
		}
		curr = curr->next;
	}
}

/**
 * @brief リダクレクトのファイル名をすべて走査し、単語の展開を試みる。
 *
 * @param redirects
 * @param environ
 */
static void	expand_filenames(t_redirect *redirects, t_hashmap *environ)
{
	t_redirect	*curr;
	char		*buff;

	curr = redirects;
	while (curr)
	{
		if (curr->type & NODE_RDIR)
		{
			buff = NULL;
			ft_wordexp(curr->file, &buff, environ);
			free(curr->file);
			if (buff)
				curr->file = ft_strdup(buff);
			else
				curr->file = ft_strdup("");
			free(buff);
		}
		curr = curr->next;
	}
}

/**
* @brief 抽象構文木の各ノードを走査し、それがコマンドである場合は展開を試みる。
 *
 * @param node
 * @param msh
 */
static void	expand_node(t_ast_node *node, t_shell *msh)
{
	if (!node)
		return ;
	if (node->type & NODE_COMMAND)
	{
		expand_arguments(node->command->arguments, msh->envs);
		expand_filenames(node->command->redirects, msh->envs);
	}
	expand_node(node->left, msh);
	expand_node(node->right, msh);
}

/**
 * @brief コマンドラインの文字列を展開する。
 *
 * @param syntax_tree
 * @param msh
 */
void	expander(t_ast_node *syntax_tree, t_shell *msh)
{
	expand_node(syntax_tree, msh);
}
