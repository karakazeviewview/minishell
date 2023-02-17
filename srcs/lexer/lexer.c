/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:10:46 by event             #+#    #+#             */
/*   Updated: 2023/02/02 15:02:18 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file lexer.c
 * @brief 字句解析のエントリーポイント
 * @version 0.1
 * @date 2023-01-01
 *
 */

#include "terminal.h"
#include "lexer.h"

/**
 * @brief 字句解析のエントリーポイント
 *
 * @param line
 * @return t_vector*
 */
void	lexer(char *line, t_vector **tokens)
{
	t_tokenizer	*tokenizer;
	t_state_fn	next_fn;

	tokenizer = init_tokenizer(line);
	while (tokenizer->state != NULL)
	{
		next_fn = (t_state_fn)tokenizer->state;
		tokenizer->state = next_fn(tokenizer);
	}
	*tokens = tokenizer->tokens;
	free(tokenizer);
}
