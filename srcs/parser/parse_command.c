/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:13:08 by event             #+#    #+#             */
/*   Updated: 2023/02/11 22:47:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_command.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 構文解析その4：コマンドパス ex."echo", "./bin/ls*""
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "parser.h"

/**
 * @note
 *	[BNF]
 * <cmd_suffix>	::= 			 <io_redirect>
 *				|	<cmd_suffix> <io_redirect>
 *				|				 word
 *				|	<cmd_suffix> word
 *	[EBNF]
 * cmd_suffix	::= word { io_redirect | word }
 */

/**
 * @brief コマンドの引数・リダイレクトの解析
 * @param tokens
 * @param curr
 * @return t_word*
 */
t_command	*parse_suffix(t_vector *tokens, t_token **curr)
{
	t_command	*command;
	t_argument	*argument;
	t_redirect	*redirect;

	command = ast_command_create();
	while (true)
	{
		if ((*curr)->type & TOKEN_STR)
		{
			argument = parse_argument(tokens, curr);
			ast_append_argument(command, argument);
		}
		else if ((*curr)->type & TOKEN_RDIR)
		{
			redirect = parse_io_redirect(tokens, curr);
			ast_append_redirect(command, redirect);
		}
		else
			break ;
	}
	return (command);
}

/**
 * @note
 * [BNF]
 * <simple_cmd>		::= cmd_name
 *					|	cmd_name <cmd_suffix>
 * [EBNF]
 * cmd_suffix		::= cmd_name | cmd_suffix ?
 */

/**
 * @brief コマンドの解析
 * @param tokens
 * @param curr
 * @return t_ast_node*
 */
t_ast_node	*parse_simple_cmd(t_vector *tokens, t_token **curr)
{
	t_ast_node	*node;

	if ((*curr)->type & TOKEN_END)
		return (NULL);
	node = ast_node_create();
	node->command = parse_suffix(tokens, curr);
	ast_node_set_type(node, NODE_COMMAND);
	return (node);
}
