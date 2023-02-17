/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:34:05 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:42:14 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static char	*get_exit_status(void)
{
	extern int	g_status;
	char		*exit_status;

	exit_status = ft_itoa(g_status);
	if (!exit_status)
		exit(EXIT_FAILURE);
	return (exit_status);
}

static int	we_parse_special(t_wordexp *we, size_t *offset)
{
	char	*exit_status;

	++*offset;
	exit_status = get_exit_status();
	we_addstr(we, exit_status);
	free(exit_status);
	return (FTWRDE_SUCCESS);
}

/**
 * @brief '$'以降の文字列を走査する。
 * @detail '{}'以外の括弧は未実装
 * @param str
 * @param offset
 * @param environ
 */
int	we_parse_dollar(char *words, t_wordexp *we, size_t *offset)
{
	if (words[*offset] == '"' || words[*offset] == '\0'
		|| words[*offset] == ' ')
	{
		we_addchar(we, '$');
		return (FTWRDE_SUCCESS);
	}
	else if (words[*offset] == '?')
		return (we_parse_special(we, offset));
	else
		return (we_parse_params(words, we, offset));
	return (FTWRDE_SUCCESS);
}
