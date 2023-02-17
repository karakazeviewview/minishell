/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:48 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:49:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

/**
 * @brief 環境変数を検索し、見つかればその文字列を返す。見つからなければ空文字列を返す。
 *
 * @param key
 * @param environ
 * @return char*
 */
static char	*search_environment(char *key, t_hashmap *environ)
{
	char	*value;

	if (!ft_hashmap_find(environ, key, (void **)&value))
		return (ft_calloc(1, sizeof(char)));
	return (value);
}

static int	we_envsubst(char *words, t_wordexp *wp, size_t var_start, \
	size_t var_end)
{
	char	*var;
	char	*env;

	var = ft_substr(words, var_start, var_end - var_start);
	env = search_environment(var, wp->envs);
	free(var);
	if (!*env)
	{
		free(env);
		return (FTWRDE_BADCHAR);
	}
	we_addstr(wp, env);
	if (!*wp->buff)
		return (FTWRDE_NOSPACE);
	return (FTWRDE_SUCCESS);
}

/**
 * @brief 変数が波括弧{}で閉じられているか判定する
 *
 * @param str
 * @param var_start
 * @param offset
 * @return true
 * @return false
 */
static bool	is_valid_syntax(char *str, size_t var_start, size_t *offset)
{
	if (str[var_start - 1] == '{')
	{
		if (str[*offset] == '}')
		{
			++*offset;
			return (true);
		}
		return (false);
	}
	return (true);
}

/**
 * @brief 変数の終端までインデックスを進める。
 * @detail 注：環境変数は英字および'_'で始める必要がある。
 * @param str
 * @param offset
 */
static void	forward_to_var_end(char *words, size_t *offset)
{
	while (true)
	{
		++*offset;
		if (!ft_isalnum(words[*offset]) && words[*offset] != '_')
			break ;
	}
}

int	we_parse_params(char *words, t_wordexp *wp, size_t *offset)
{
	size_t	var_start;
	size_t	var_end;

	if (words[*offset] == '{')
		++*offset;
	var_start = *offset;
	if (ft_isalpha(words[*offset]) || words[*offset] == '_')
	{
		forward_to_var_end(words, offset);
		var_end = *offset;
		if (is_valid_syntax(words, var_start, offset))
		{
			we_envsubst(words, wp, var_start, var_end);
		}
		else
			return (FTWRDE_SYNTAX);
	}
	return (FTWRDE_SUCCESS);
}
