/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:58:18 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 13:07:57 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file env.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief ビルトイン - envコマンド
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ft_printf.h"
#include "terminal.h"

static int	print_env(t_hashmap_data *map_data, void *data)
{
	char	*key;
	char	*value;

	(void)data;
	if (map_data->key && map_data->value)
	{
		key = map_data->key;
		value = (char *)map_data->value;
		if (*key && *value)
			ft_printf("%s=%s\n", map_data->key, map_data->value);
	}
	return (1);
}

int	builtin_env(char **args, t_shell *msh)
{
	if (!args[1] || !*args[1])
	{
		ft_hashmap_iterate(msh->envs, print_env, NULL);
	}
	return (0);
}
