/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:24:14 by event             #+#    #+#             */
/*   Updated: 2023/02/02 04:37:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libast.h"
#include <stdlib.h>

void	ast_arguments_delete(t_argument *arguments)
{
	t_argument	*tmp;

	while (arguments)
	{
		tmp = arguments->next;
		free(arguments->argument);
		arguments->argument = NULL;
		free(arguments);
		arguments = tmp;
	}
	free(arguments);
}

void	ast_redirects_delete(t_redirect *redirects)
{
	t_redirect	*tmp;

	while (redirects)
	{
		tmp = redirects->next;
		free(redirects->file);
		redirects->file = NULL;
		free(redirects);
		redirects = tmp;
	}
	free(redirects);
}

void	ast_command_delete(t_command *command)
{
	if (!command)
		return ;
	if (command->redirects)
		ast_redirects_delete(command->redirects);
	if (command->arguments)
		ast_arguments_delete(command->arguments);
	free(command);
}

void	ast_node_delete(t_ast_node *node)
{
	if (!node)
		return ;
	if (node->command)
		ast_command_delete(node->command);
	ast_node_delete(node->left);
	ast_node_delete(node->right);
	free(node);
}
