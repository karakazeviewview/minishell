/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:58:29 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 17:27:29 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file unset.c
 * @brief ビルトイン - unsetコマンド
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "terminal.h"

int	builtin_unset(char **args, t_shell *msh)
{
	size_t	i;

	i = 1;
	while (args[i])
	{
		ft_unsetenv(args[i], msh->envs);
		i++;
	}
	return (0);
}
