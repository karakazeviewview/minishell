/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:59:01 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 15:52:01 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @file main.c
* @brief main関数および管理情報の初期化。
* @author tmuramat
* @date 2022.12.30
*/

#include "terminal.h"

/**
 * @brief シェルの管理情報を初期化する。
 * @details 処理を通して環境変数・プロンプト名・親/子プロセスの情報を保持する。
 * @return t_shell*
 */
t_shell	*init_minishell(void)
{
	t_shell	*msh;

	msh = (t_shell *)ft_xmalloc(sizeof(t_shell));
	msh->envs = init_environ();
	msh->prompt = get_prompt();
	msh->pids = ft_deque_init(sizeof(pid_t), 1);
	return (msh);
}

/**
 ***************************************************************
 *	function: main
 *
 *  A re-implemention of the Linux Bash shell.
 ***************************************************************
*/
int	main(void)
{
	t_shell	*msh;

	msh = init_minishell();
//	put_banner();
	if (DEBUG)
		terminal_dev(msh);
	else
		terminal(msh);
	return (0);
}
