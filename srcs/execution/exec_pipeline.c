/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:02:45 by event             #+#    #+#             */
/*   Updated: 2023/02/13 01:24:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libast.h"

/**
 * @brief パイプ間のコマンドを順に実行する。
 * @param node
 * @param process
 * @param msh
 * @param pipe
 */
static void	_do_pipes(t_ast_node *node, t_process process, t_shell *msh)
{
	process.pipes.state = PIPE_STDOUT;
	while (node->right)
	{
		exec_simple_cmd(node->left, process, msh);
		process.pipes.state = PIPE_STDOUT | PIPE_STDIN;
		process.pipes.idx += 2;
		node = node->right;
	}
	process.pipes.state = PIPE_STDIN;
	exec_simple_cmd(node, process, msh);
}

/**
 * @brief 実行処理：パイプライン（"|"）
 *
 * @param node
 * @param msh
 */
void	exec_pipeline(t_ast_node *node, t_process process, t_shell *msh)
{
	size_t		cnt;

	cnt = ast_count_pipeline(node);
	if (cnt <= 1)
		process.is_solo = true;
	process.pipes = init_pipeline(cnt);
	_do_pipes(node, process, msh);
	delete_pipeline(process.pipes);
	if (msh->is_child_process == true)
		wait_all_child_processes(msh);
}
