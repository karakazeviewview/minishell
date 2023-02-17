/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:21:57 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 22:04:38 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# ifdef DEBUG
#  define DEBUG 1
# else
#  define DEBUG 0
# endif

# include "libft.h"
# include "constant.h"
# include "ft_hashmap.h"
# include "ft_vector.h"
# include "ft_deque.h"
# include "libast.h"
# include "lexer.h"

typedef struct s_env {
	char	*key;
	char	*value;
}	t_env;

typedef struct s_shell {
	t_hashmap	*envs;
	char		*prompt;
	int			exit_status;
	int			is_child_process;
	t_deque		*pids;
}	t_shell;

/************* terinal ***************/
t_shell		*init_minishell(void);
void		terminal(t_shell *msh);

/******* Environent variables ********/
t_hashmap	*init_environ(void);
t_env		parse_environ(const char *str);
void		sort_environs(t_env *env);
char		*ft_getenv(const char *key, t_hashmap *envs);
int			ft_setenv(t_env *env, t_hashmap *envs, int overwrite);
int			ft_unsetenv(const char *key, t_hashmap *envs);
int			ft_putenv(t_env *env, t_hashmap *envs);

/*************  Prompt ***************/
char		*get_prompt(void);
void		put_banner(void);

/*************  Signal ***********/
void		set_ignore_signal(void);
void		set_signal(int signal, void (*sighandler)(int));
void		reset_signals(void);

/*********** Error **********/
void		shell_perror(const char *string, t_shell *msh, int status);
void		maybe_exit(int status, t_shell *msh);
void		builtin_perror(char *string, char *arg, char *cmd, t_shell *msh);

//********** debug command ********/
void		terminal_dev(t_shell *msh);
void		print_tokens(t_vector *tokens);
void		print_nodes(t_ast_node *node);
void		print_commands(t_ast_node *node);
void		print_output(void);
void		print_input(char *line);
char		*get_node_type(t_node_type	type);

#endif
