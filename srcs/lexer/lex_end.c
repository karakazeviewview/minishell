/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:06:02 by event             #+#    #+#             */
/*   Updated: 2023/02/04 13:29:00 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief 状態遷移：エラーの場合
 *
 * @param tokenizer
 * @return void*
 */
void	*lex_error(t_tokenizer *tokenizer)
{
	(void)tokenizer;
	return (NULL);
}

/**
 * @brief 状態遷移：終端（EOF）の場合
 *
 * @param tokenizer
 * @return void*
 */
void	*lex_eof(t_tokenizer *tokenizer)
{
	token_next(tokenizer);
	token_emit(tokenizer, TOKEN_END);
	return (NULL);
}
