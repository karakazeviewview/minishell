/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:10 by event             #+#    #+#             */
/*   Updated: 2023/02/04 14:31:12 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_pipeline.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 構文解析その2：パイプライン "|"
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "parser.h"

/**
 * @note
 * [BNF]
 * <pipeline>		::=	<simple_cmd> '|' <pipeline>
 *					|	<simple_cmd>
 * [EBNF]
 *	pipeline		::= simple_cmd { '|' simple_cmd }
 */

/**
 * @brief パイプの解析
 *
 * @param tokens
 * @param curr
 * @return t_ast_node*
 */

t_ast_node	*parse_pipeline(t_vector *tokens, t_token **curr)
{
	t_ast_node	*right_node;
	t_ast_node	*node;

	right_node = NULL;
	if ((*curr)->type & TOKEN_END)
		return (NULL);
	node = parse_simple_cmd(tokens, curr);
	if ((*curr)->type & TOKEN_PIPELINE)
	{
		next_token(tokens, curr);
		right_node = parse_pipeline(tokens, curr);
		node = ast_parent_create(node, right_node);
		ast_node_set_type(node, NODE_PIPELINE);
	}
	return (node);
}
