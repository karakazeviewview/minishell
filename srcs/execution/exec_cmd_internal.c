/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:21:57 by event             #+#    #+#             */
/*   Updated: 2023/02/11 16:26:37 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file command.c
 * @author tmuramat (tmuramat@student.42tokyo.jp)
 * @brief 内部・外部コマンドの実行
 * @version 0.1
 * @date 2023-01-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "terminal.h"
#include "execution.h"
#include "parser.h"
#include "libast.h"
#include "ft_printf.h"

/**
 * @brief ビルトイン関数群
 *
 */
static const t_builtin	g_builtins[8] = {
{"echo", &builtin_echo},
{"cd", &builtin_cd},
{"pwd", &builtin_pwd},
{"export", &builtin_export},
{"unset", &builtin_unset},
{"env", &builtin_env},
{"exit", &builtin_exit},
{NULL, NULL},
};

t_builtin_fn	search_builtin(t_process *process)
{
	size_t	i;

	if (!process || !process->argv || !process->argv[0])
		return (NULL);
	i = 0;
	while (g_builtins[i].symbol)
	{
		if (!ft_strcmp(process->argv[0], g_builtins[i].symbol))
			return ((t_builtin_fn)g_builtins[i].func);
		i++;
	}
	return (NULL);
}

/**
 * @brief 内部コマンドを実行する
 *
 * @param args　コマンドに渡す引数の配列（[0]はコマンド名）
 * @param msh シェルの管理情報
 * @return int 実行したコマンドの戻り値を返す。コマンドが見つからなければ1を返す。
 */
void	exec_internal_command(t_builtin_fn bltin_cmd, t_process process, \
	t_shell *msh)
{
	int			status;

	status = (*bltin_cmd)(process.argv, msh);
	maybe_exit(status, msh);
}
