/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:33:43 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/13 01:31:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file signal.c
 * @brief シグナルハンドラーの設定
 * @date 2023-01-01
 */

#include <terminal.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <sys/ioctl.h>

/**
 * @brief SIGINT用シグナルハンドラー
 * @detail READLINEに対する文字出力を抑え、改行する。
 * @param signal 設定対象のシグナル
 */
void	ignore_sighandler(int signal)
{
	extern int	g_status;

	if (signal == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

/**
 * @brief 対象のシグナルにシグナルハンドラーを設定する。
 *
 * @param signal 設定対象のシグナル
 * @param sighandler　設定するシグナルハンドラー
 */
void	set_signal(int signal, void (*sighandler)(int))
{
	struct sigaction	sa;

	sa = (struct sigaction){};
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sighandler;
	if (sigaction(signal, &sa, NULL) < 0)
		exit(EXIT_FAILURE);
}

void	reset_signals(void)
{
	set_signal(SIGINT, SIG_DFL);
	set_signal(SIGQUIT, SIG_DFL);
	set_signal(SIGTSTP, SIG_DFL);
}

/**
 * @brief SIGINT, SIGSTOP, SIGQUITのシグナルを無効化する。
 * @detail SIGINTのみ別途シグナルハンドラーを設定する。
 */
void	set_ignore_signal(void)
{
	set_signal(SIGINT, ignore_sighandler);
	set_signal(SIGQUIT, SIG_IGN);
	set_signal(SIGTSTP, SIG_IGN);
}
