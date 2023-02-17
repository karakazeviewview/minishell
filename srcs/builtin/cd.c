/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:22:46 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 16:53:29 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cd.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief ビルトイン - cdコマンド
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <limits.h>
#include "execution.h"

static int	update_old_pwd(char *old_path, t_shell *msh)
{
	t_env	env;

	env.key = ft_strdup("OLDPWD");
	env.value = ft_strdup(old_path);
	return (ft_putenv(&env, msh->envs));
}

static int	update_new_pwd(t_shell *msh)
{
	t_env	env;
	char	curr_path[PATH_MAX];

	getcwd(curr_path, PATH_MAX);
	env.key = ft_strdup("PWD");
	env.value = ft_strdup(curr_path);
	return (ft_putenv(&env, msh->envs));
}

int	builtin_cd(char **args, t_shell *msh)
{
	char	*dst_path;
	char	curr_path[PATH_MAX];

	if (!args || !*args)
		return (1);
	getcwd(curr_path, PATH_MAX);
	if (!args[1])
		dst_path = ft_getenv("HOME", msh->envs);
	else
		dst_path = args[1];
	if (chdir(dst_path))
	{
		errno = ENOENT;
		builtin_perror(MSG_NO_FILE_DIR, dst_path, args[0], msh);
		return (1);
	}
	if (!update_old_pwd(curr_path, msh) || !update_new_pwd(msh))
		return (-1);
	return (0);
}
