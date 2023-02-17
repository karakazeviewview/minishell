/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:26:01 by event             #+#    #+#             */
/*   Updated: 2023/01/16 08:26:02 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libast.h"
#include <stdlib.h>

void	ast_node_set_type(t_ast_node *node, t_node_type type)
{
	if (!node)
		return ;
	node->type = type;
}

void	ast_append_redirect(t_command *command, t_redirect *new_redirect)
{
	t_redirect	*curr;

	if (!command->redirects)
	{
		command->redirects = new_redirect;
		return ;
	}
	curr = command->redirects;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_redirect;
}

void	ast_append_argument(t_command *command, t_argument *new_arg)
{
	t_argument	*curr;

	if (!command->arguments)
	{
		command->arguments = new_arg;
		return ;
	}
	curr = command->arguments;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_arg;
}
