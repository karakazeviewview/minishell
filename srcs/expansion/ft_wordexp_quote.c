/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:13:47 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:35:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

/**
 * @brief ダブルクオート’"'以降の文字列を走査する。
 *
 * @param str
 * @param buff
 * @param offset
 */
static int	we_parse_double_quote(char *words, t_wordexp *we, size_t *offset)
{
	while (words[*offset])
	{
		if (words[*offset] == '"')
		{
			++*offset;
			return (FTWRDE_SUCCESS);
		}
		else if (words[*offset] == '$')
		{
			return (we_parse_dollar(words, we, offset));
		}
		else
		{
			we_addchar(we, words[*offset]);
			if (!*we->buff)
				return (FTWRDE_NOSPACE);
		}
		++*offset;
	}
	return (FTWRDE_SYNTAX);
}

static int	we_parse_single_quote(char *words, t_wordexp *we, size_t *offset)
{
	while (words[*offset])
	{
		if (words[*offset] == '\'')
		{
			++*offset;
			return (FTWRDE_SUCCESS);
		}
		else
		{
			we_addchar(we, words[*offset]);
			if (!*we->buff)
				return (FTWRDE_NOSPACE);
		}
		++*offset;
	}
	return (FTWRDE_SYNTAX);
}

int	we_parse_quote(char *words, t_wordexp *wp, size_t *offset)
{
	if (words[*offset - 1] == '\'')
	{
		we_parse_single_quote(words, wp, offset);
	}
	else if (words[*offset - 1] == '"')
	{
		we_parse_double_quote(words, wp, offset);
	}
	return (0);
}
