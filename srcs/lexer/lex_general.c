/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:06:30 by event             #+#    #+#             */
/*   Updated: 2023/02/05 21:21:14 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

bool	ft_isquote(int c)
{
	if (c == '\'' || c == '"')
		return (true);
	return (false);
}

bool	ft_isnull(int c)
{
	if (c == '\0')
		return (true);
	return (false);
}

bool	is_redirection(int c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	is_delimiter(int c)
{
	if (ft_isspace(c) || ft_isnull(c)
		|| is_redirection(c) || c == '|' || c == ';')
		return (true);
	return (false);
}

/**
 * @brief 状態遷移：通常（ここから各状態に遷移する）。
 *
 * @param tokenizer
 * @return void*
 */
void	*lex_general(t_tokenizer *tokenizer)
{
	char	next_c;

	next_c = token_peek(tokenizer);
	if (ft_isspace(next_c) == true)
		return (lex_whitespace);
	else if (ft_isnull(next_c) == true)
		return (lex_eof);
	else if (ft_isquote(next_c) == true)
		return (lex_quote);
	else if (is_redirection(next_c) == true)
		return (lex_redirect);
	else if (is_delimiter(next_c) == true)
		return (lex_delimiter);
	else
		return (lex_string);
	token_emit(tokenizer, TOKEN_NONE);
	return (NULL);
}
