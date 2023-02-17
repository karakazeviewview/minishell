/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:23:36 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 17:31:23 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file exit.c
 * @brief ビルトイン - exitコマンド
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "terminal.h"

static void	put_error(char *message, int status)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(status);
}

static int	input_args(char **argv)
{
	char	*endptr;
	long	long_num;

	errno = 0;
	endptr = NULL;
	long_num = ft_strtol_d(argv[1], &endptr);
	if ((long_num == LONG_MIN || long_num == LONG_MAX) \
		&& errno == ERANGE)
		put_error(MSG_NUM_ARG_REQUIRED, 255);
	else if (*endptr || endptr == argv[1])
		put_error(MSG_NUM_ARG_REQUIRED, 255);
	return ((int)long_num);
}

int	builtin_exit(char **argv, t_shell *msh)
{
	size_t		argc;
	extern int	g_status;

	(void)msh;
	argc = ft_matrixlen((const char **)argv);
	if (argc > 2)
		put_error(MSG_TOO_MANY_ARGS, 1);
	if (argc == 2)
		exit(input_args(argv));
	ft_putendl_fd("exit", STDERR_FILENO);
	exit(g_status & 0xFF);
	return (0);
}
