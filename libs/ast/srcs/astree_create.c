/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:22:11 by event             #+#    #+#             */
/*   Updated: 2023/02/04 14:29:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libast.h"
#include <stdlib.h>

/**
 * @brief Create an Redirection node.
 *
 * @param dir
 * @param fd
 * @param file
 * @return t_redirect*
 */
t_redirect	*ast_redirect_create(int dir, int fd, char *file)
{
	t_redirect	*new_redirect;

	new_redirect = malloc(sizeof(t_redirect));
	if (!new_redirect)
		return (NULL);
	new_redirect->type = dir;
	new_redirect->fd = fd;
	new_redirect->file = file;
	new_redirect->next = NULL;
	return (new_redirect);
}

/**
 * @brief Create an Argument node.
 *
 * @param arg
 * @return t_argument*
 */
t_argument	*ast_argument_create(char *arg, t_node_type type)
{
	t_argument	*new_arg;

	new_arg = malloc(sizeof(t_argument));
	if (!arg)
		return (NULL);
	new_arg->argument = arg;
	new_arg->type = type;
	new_arg->next = NULL;
	return (new_arg);
}

/**
 * @brief Create a Command node.
 *
 * @return t_command*
 */
t_command	*ast_command_create(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->arguments = NULL;
	command->redirects = NULL;
	return (command);
}

t_ast_node	*ast_node_create(void)
{
	t_ast_node	*node;

	node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->command = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * @brief Create a Parent-Children-related node.
 *
 * @param left pointer to a left node.
 * @param right pointer to a right node.
 * @return t_ast_node*
 */
t_ast_node	*ast_parent_create(t_ast_node *left, t_ast_node *right)
{
	t_ast_node	*node;

	node = ast_node_create();
	if (!node)
		return (NULL);
	node->left = left;
	node->right = right;
	node->command = ast_command_create();
	return (node);
}
