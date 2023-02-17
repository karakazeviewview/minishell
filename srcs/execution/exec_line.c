/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:18:22 by event             #+#    #+#             */
/*   Updated: 2023/01/27 01:18:23 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "libast.h"

/**
 * @brief 実行処理：セパレーター"；"
 *
 * @param node
 * @param msh
 */
void	exec_command_line(t_ast_node *node, t_process process, t_shell *msh)
{
	if (!node)
		return ;
	if (node->type & NODE_SEQUENCE)
	{
		exec_pipeline(node->left, process, msh);
		exec_command_line(node->right, process, msh);
		return ;
	}
	exec_pipeline(node, process, msh);
}
