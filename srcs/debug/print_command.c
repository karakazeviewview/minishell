/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:24:19 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/13 01:14:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "ft_printf.h"

static void	dbg_print_arguments(t_ast_node *node)
{
	t_argument	*curr;

	ft_printf("cmd: ");
	curr = node->command->arguments;
	while (curr)
	{
		ft_printf("%s, ", curr->argument);
		curr = curr->next;
	}
	ft_printf("\n");
}

static void	dbg_print_filenames(t_ast_node *node)
{
	t_redirect	*curr;

	ft_printf("io: ");
	curr = node->command->redirects;
	while (curr)
	{
		ft_printf("%s, ", curr->file);
		curr = curr->next;
	}
	ft_printf("\n");
}

static void	print_commands_rec(t_ast_node *node)
{
	if (!node)
		return ;
	print_commands_rec(node->left);
	if (node->type & NODE_COMMAND)
	{
		dbg_print_arguments(node);
		dbg_print_filenames(node);
	}
	print_commands_rec(node->right);
}

void	print_commands(t_ast_node *syntax_tree)
{
	ft_printf("%s>>>> EXPANDER >>>>", CYAN);
	ft_printf("\n===============================================\n");
	print_commands_rec(syntax_tree);
	ft_printf("===============================================%s\n\n", DEFAULT);
}
