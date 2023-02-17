/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:24:01 by event             #+#    #+#             */
/*   Updated: 2023/02/13 00:17:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <signal.h>

pid_t	create_child_process(t_shell *msh)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (msh)
		ft_deque_push_back(msh->pids, &pid);
	return (pid);
}

void	set_exit_status(int status)
{
	int			signal;
	extern int	g_status;

	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		if (signal == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
		g_status = signal + 128;
	}
}

void	wait_all_child_processes(t_shell *msh)
{
	int		status;
	bool	seen_sigint;
	int		next_pid;

	seen_sigint = false;
	while (!ft_deque_is_empty(msh->pids))
	{
		ft_deque_pop_front(msh->pids, &next_pid);
		while (waitpid(next_pid, &status, 0) >= 0)
			;
	}
	set_exit_status(status);
}

void	wait_child_process(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) < 0)
		exit(EXIT_FAILURE);
}
