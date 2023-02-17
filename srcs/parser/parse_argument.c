/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:12:43 by event             #+#    #+#             */
/*   Updated: 2023/02/04 13:19:39 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_argument.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 構文解析その5：引数 ex."-n", "hello"
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
 * <word> := word
 * [EBNF]
 * word := 'word'
 */

/**
 * @brief 引数の解析
 *
 * @param tokens
 * @param curr
 * @return t_argument*
 */
t_argument	*parse_argument(t_vector *tokens, t_token **curr)
{
	char		*arg;
	t_node_type	type;

	type = NODE_WORD;
	arg = scan_token(tokens, curr);
	return (ast_argument_create(arg, type));
}
