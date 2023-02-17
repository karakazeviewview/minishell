/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_external.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:18:48 by event             #+#    #+#             */
/*   Updated: 2023/02/14 00:08:10 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "execution.h"
#include "parser.h"
#include "libast.h"
#include "ft_printf.h"
#include "constant.h"
#include <unistd.h>
#include <fcntl.h>

static void	command_perror(char *command, t_shell *msh)
{
	ft_putstr_fd(PROMPT_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (command)
	{
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(MSG_CMD_NOT_FOUND, STDERR_FILENO);
	maybe_exit(127, msh);
}

/**
 * @brief 外部コマンドを実行する
 *
 * @param process コマンド実行の管理情報
 * @param msh シェルの管理情報
 */
void	exec_external_command(t_process process, t_shell *msh)
{
	extern int	g_status;

	if (!process.argv || !process.argv[0])
		exit(EXIT_SUCCESS);
	ft_execvpe(process.argv[0], process.argv, construct_environ(msh->envs));
	if (errno == EISDIR || errno == EACCES)
		shell_perror(process.argv[0], msh, 126);
	else if (errno == ENOENT)
		shell_perror(process.argv[0], msh, 127);
	command_perror(process.argv[0], msh);
}
