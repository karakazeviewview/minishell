/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_whitespace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:10:01 by event             #+#    #+#             */
/*   Updated: 2023/02/04 13:29:57 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

/** 状態遷移：空白の場合
 * @brief
 *
 * @param tokenizer
 * @return void*
 */
void	*lex_whitespace(t_tokenizer *tokenizer)
{
	token_next(tokenizer);
	while (ft_isspace(token_peek(tokenizer)) == true)
	{
		token_next(tokenizer);
	}
	return (lex_general);
}
