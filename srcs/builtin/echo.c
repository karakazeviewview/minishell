/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:23:13 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/11 22:23:18 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file echo.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief ビルトイン - echoコマンド
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "terminal.h"

int	is_n_option(const char *str)
{
	if (ft_strcmp(str, "-n") != 0)
		return (0);
	str++;
	while (*str == 'n')
		str++;
	if (!(*str))
		return (1);
	return (0);
}

bool	parse_option(char **args, size_t *i)
{
	bool	is_newline;

	is_newline = true;
	while (args[*i] && is_n_option(args[*i]))
	{
		is_newline = false;
		++*i;
	}
	return (is_newline);
}

int	builtin_echo(char **args, t_shell *msh)
{
	size_t	i;
	size_t	len;
	bool	is_newline;

	(void)msh;
	len = ft_matrixlen((const char **)args);
	if (len == 1)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	i = 1;
	is_newline = parse_option(args, &i);
	while (i < len)
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		i++;
		if (i != len)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (is_newline == true)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
