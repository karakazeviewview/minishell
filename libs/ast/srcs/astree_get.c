/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:25:16 by event             #+#    #+#             */
/*   Updated: 2023/02/11 22:38:53 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libast.h"

size_t	ast_count_nodes(t_ast_node *root)
{
	if (root == NULL)
		return (0);
	return (1 + ast_count_nodes(root->left) + ast_count_nodes(root->right));
}

size_t	ast_count_arguments(t_argument *arguments)
{
	size_t	count;

	count = 0;
	while (arguments)
	{
		count += 1;
		arguments = arguments->next;
	}
	return (count);
}

size_t	ast_count_redirects(t_redirect *redirects)
{
	size_t	count;

	count = 0;
	while (redirects)
	{
		count += 1;
		redirects = redirects->next;
	}
	return (count);
}

char	*ast_get_command_name(t_command *command)
{
	return (command->arguments->argument);
}

size_t	ast_count_pipeline(t_ast_node *node)
{
	size_t		count;
	t_ast_node	*tmp_node;

	tmp_node = node;
	count = 0;
	while (tmp_node)
	{
		count += 1;
		tmp_node = tmp_node->right;
	}
	return (count);
}
