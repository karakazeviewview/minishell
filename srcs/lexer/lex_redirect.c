/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:09:22 by event             #+#    #+#             */
/*   Updated: 2023/02/04 13:39:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief 状態遷移：リダイレクトが連続する（">>"および"<<"）場合
 *
 * @param tokenizer
 * @param current
 * @return void*
 */
static void	lex_redirect_double(t_tokenizer *tokenizer, char current)
{
	t_token_type	type;
	char			next_c;

	next_c = token_next(tokenizer);
	if (current == '>' && next_c == '>')
		type = TOKEN_RDIR_APPEND;
	else if (current == '<' && next_c == '<')
		type = TOKEN_RDIR_HEREDOC;
	else
		type = TOKEN_NONE;
	token_emit(tokenizer, type);
}

/**
 * @brief 状態遷移：リダイレクト（">"および"<"）の場合
 *
 * @param tokenizer
 * @return void*
 */
void	*lex_redirect(t_tokenizer *tokenizer)
{
	t_token_type	type;
	char			current;

	current = token_next(tokenizer);
	if (is_redirection(token_peek(tokenizer)) == true)
	{
		lex_redirect_double(tokenizer, current);
		return (lex_general);
	}
	if (current == '<')
		type = TOKEN_RDIR_INPUT;
	else if (current == '>')
		type = TOKEN_RDIR_OUTPUT;
	else
		type = TOKEN_NONE;
	token_emit(tokenizer, type);
	return (lex_general);
}
