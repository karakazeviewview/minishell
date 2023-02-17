/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:34:35 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:46:16 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include <assert.h>

static void	_we_addmem(t_wordexp *we, const char *str, size_t len)
{
	char	*old_buff;
	char	*p_end;

	if (we->act_len + len > we->max_len)
	{
		old_buff = *we->buff;
		we->max_len += (len * 2);
		*we->buff = ft_realloc(old_buff, 1 + we->max_len);
		if (!*we->buff)
			free(old_buff);
	}
	if (*we->buff)
	{
		p_end = ft_mempcpy(&(*we->buff)[we->act_len], str, len);
		*p_end = '\0';
		we->act_len += len;
	}
}

void	we_addstr(t_wordexp *we, const char *str)
{
	size_t	len;

	if (!str)
		exit (EXIT_FAILURE);
	len = ft_max(1, ft_strlen(str));
	_we_addmem(we, str, len);
}

void	we_addchar(t_wordexp *we, char ch)
{
	char	*old_buff;

	if (we->act_len == we->max_len)
	{
		old_buff = *we->buff;
		we->max_len += 16;
		*we->buff = (char *)ft_realloc(old_buff, 1 + we->max_len);
		if (!*we->buff)
			free(old_buff);
	}
	if (*we->buff)
	{
		(*we->buff)[we->act_len] = ch;
		(*we->buff)[++we->act_len] = '\0';
	}
}

t_wordexp	we_newword(char **buff, t_hashmap *environs)
{
	t_wordexp	wordexp;

	wordexp.buff = buff;
	wordexp.act_len = 0;
	wordexp.max_len = 0;
	wordexp.envs = environs;
	return (wordexp);
}
