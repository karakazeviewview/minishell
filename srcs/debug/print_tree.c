/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:25:01 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:51:53 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_tree.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 構文解析デバッグ用のAST出力
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fcntl.h>
#include "lexer.h"
#include "terminal.h"
#include "parser.h"
#include "ft_printf.h"

#define INDENT "    "

char	*get_node_type(t_node_type	type)
{
	if (type & NODE_PIPELINE)
		return ("[PIPELINE]");
	else if (type & NODE_SEQUENCE)
		return ("[SEQUENCE]");
	else if (type & NODE_COMMAND)
		return ("[COMMAND]");
	else if (type & NODE_WORD)
		return ("[WORD]");
	else if (type & NODE_RDIR_INPUT)
		return ("<");
	else if (type & NODE_RDIR_OUTPUT)
		return (">");
	else if (type & NODE_RDIR_APPEND)
		return (">>");
	else if (type & NODE_RDIR_HEREDOC)
		return ("<<");
	return ("[N/A]");
}

void	print_node_command(t_command *command)
{
	t_argument		*arg_tmp;
	t_redirect		*redirect_tmp;

	redirect_tmp = command->redirects;
	while (redirect_tmp)
	{
		ft_printf("type: %d %s file: %s ", redirect_tmp->fd, \
			get_node_type(redirect_tmp->type), redirect_tmp->file);
		redirect_tmp = redirect_tmp->next;
	}
	arg_tmp = command->arguments;
	ft_printf("argv: ");
	while (arg_tmp)
	{
		ft_printf("%s ", arg_tmp->argument);
		arg_tmp = arg_tmp->next;
	}
}

void	print_node(t_ast_node *node)
{
	ft_printf("-");
	ft_printf("%s ", get_node_type(node->type));
	if (node->type & NODE_COMMAND)
		print_node_command(node->command);
	ft_printf("\n");
}

void	print_nodes_rec(t_ast_node *node, int depth)
{
	if (!node)
		return ;
	print_nodes_rec(node->left, depth + 1);
	while (depth--)
		ft_printf("%s", INDENT);
	print_node(node);
	print_nodes_rec(node->right, depth + 1);
}

void	print_nodes(t_ast_node *node)
{
	ft_printf("\n%s>>>> PARSER >>>>", GREEN);
	ft_printf("\n===============================================\n");
	print_nodes_rec(node, 0);
	ft_printf("===============================================%s\n\n", DEFAULT);
}
