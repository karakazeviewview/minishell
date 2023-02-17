/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:09:23 by event             #+#    #+#             */
/*   Updated: 2023/02/06 01:37:20 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBAST_H
# define LIBAST_H

# include <stdio.h>

typedef struct s_ast_node	t_ast_node;
typedef struct s_ast		t_ast;
typedef enum e_node_type	t_node_type;
typedef struct s_data		t_data;
typedef struct s_redirect	t_redirect;
typedef struct s_command	t_command;
typedef struct s_argument	t_argument;

enum	e_node_type {
	NODE_NONE			= 0,
	NODE_PIPELINE		= (1 << 0),
	NODE_SEQUENCE		= (1 << 1),
	NODE_RDIR_INPUT		= (1 << 2),
	NODE_RDIR_APPEND	= (1 << 3),
	NODE_RDIR_OUTPUT	= (1 << 4),
	NODE_RDIR_HEREDOC	= (1 << 5),
	NODE_COMMAND		= (1 << 6),
	NODE_WORD			= (1 << 7),
	NODE_RDIR			= NODE_RDIR_INPUT | NODE_RDIR_APPEND \
						| NODE_RDIR_OUTPUT | NODE_RDIR_HEREDOC,
	NODE_ALL			= ~0
};

/**
 * @struct t_argument
 * @brief Command arguments list.
 */
struct s_argument
{
	char		*argument;
	t_node_type	type;
	t_argument	*next;
};

/**
 * @struct t_redirect
 * @brief Command redirection list.
 */
struct s_redirect
{
	t_node_type		type;
	int				fd;
	char			*file;
	t_redirect		*next;
};

/**
 * @struct t_command_node
 * @brief Leaf node for the shell syntax.
 */
struct s_command
{
	t_argument	*arguments;
	t_redirect	*redirects;
};

/**
 * @struct t_ast_node
 * @brief Tree node for the shell syntax.
 */
struct s_ast_node
{
	t_node_type	type;
	t_ast_node	*left;
	t_ast_node	*right;
	t_command	*command;
};

/** Constructor functions */
t_ast_node	*ast_node_create(void);
t_ast_node	*ast_parent_create(t_ast_node *left, t_ast_node *right);
t_command	*ast_command_create(void);
t_argument	*ast_argument_create(char *word, t_node_type type);
t_redirect	*ast_redirect_create(int type, int fd, char *file);

/** Destructor functions */
void		ast_node_delete(t_ast_node *node);
void		ast_command_delete(t_command *command);
void		ast_arguments_delete(t_argument *arguments);
void		ast_redirects_delete(t_redirect *redirects);

/** Setter functions */
void		ast_node_set_type(t_ast_node *node, t_node_type node_type);
void		ast_append_argument(t_command *command, t_argument *new_arg);
void		ast_append_redirect(t_command *command, t_redirect *new_redirect);

/** Getter functions */
char		*ast_get_command_name(t_command *command);
size_t		ast_count_redirects(t_redirect *redirects);
size_t		ast_count_arguments(t_argument *arguments);
size_t		ast_count_pipeline(t_ast_node *node);
size_t		ast_count_nodes(t_ast_node *root);

#endif
