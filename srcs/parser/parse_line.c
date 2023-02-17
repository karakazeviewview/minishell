/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:13:33 by event             #+#    #+#             */
/*   Updated: 2023/02/04 14:04:37 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_separator.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 構文解析その1：セミコロン ";"
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "parser.h"

/**
 * @note
 * 	[BNF]
 * 	<command_line>	::= <pipeline> ';' <command_line>
 * 					|	<pipeline> ';'
 *					|	<pipeline>
 *	[EBNF]
 * 	command_line	::= pipeline { ';' command_line ? }
 */

/**
 * @brief セパレーター（";"）の解析
 *
 * @param tokens
 * @param curr
 * @return t_ast_node*
 */
t_ast_node	*parse_command_line(t_vector *tokens, t_token **curr)
{
	t_ast_node	*right_node;
	t_ast_node	*node;

	right_node = NULL;
	if ((*curr)->type & TOKEN_END)
		return (NULL);
	node = parse_pipeline(tokens, curr);
	if ((*curr)->type & TOKEN_SEMICOLON)
	{
		next_token(tokens, curr);
		right_node = parse_command_line(tokens, curr);
		node = ast_parent_create(node, right_node);
		ast_node_set_type(node, NODE_SEQUENCE);
	}
	return (node);
}
