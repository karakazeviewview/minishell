/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:19:18 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/13 23:11:12 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define PIPE_STDIN	0x1
# define PIPE_STDOUT 0x2

# include "terminal.h"
# include "libast.h"
# include "ft_hashmap.h"
# include "ft_vector.h"

typedef int	(*t_builtin_fn)(char **, t_shell *);

typedef struct s_builtin {
	char			*symbol;
	t_builtin_fn	func;
}	t_builtin;

typedef struct s_pipe {
	int		*fds;
	size_t	idx;
	int		state;
	size_t	len;
}	t_pipe;

typedef struct s_redir {
	int		fd;
	char	*file;
	int		type;
}	t_redir;

typedef struct s_process {
	char		**argv;
	t_redir		*redir;
	t_pipe		pipes;
	bool		is_solo;
}	t_process;

/********* Builtin commands **********/
int				builtin_export(char **argv, t_shell	*msh);
int				builtin_unset(char **argv, t_shell	*msh);
int				builtin_env(char **argv, t_shell *msh);
int				builtin_echo(char **argv, t_shell *msh);
int				builtin_exit(char **argv, t_shell *msh);
int				builtin_cd(char **argv, t_shell *msh);
int				builtin_pwd(char **argv, t_shell *msh);

void			executor(t_ast_node *syntax_tree, t_shell *msh);
void			exec_command_line(t_ast_node *node, t_process process, \
					t_shell *msh);
void			exec_pipeline(t_ast_node *node, t_process process, \
					t_shell *msh);
void			exec_simple_cmd(t_ast_node *node, t_process process, \
					t_shell *msh);
void			exec_internal_command(t_builtin_fn builtin_cmd, \
					t_process process, \
				t_shell *msh);
void			exec_external_command(t_process process, t_shell *msh);

t_builtin_fn	search_builtin(t_process *process);
char			**construct_environ(t_hashmap *map);

/********** ft_execvpe **********/
int				ft_execvpe(const char *file, char *const argv[], \
					char *const envp[]);
char			**convert_vector_to_array(t_vector *src);
bool			is_expected_error(bool *seen_eaccess);
bool			is_directory(const char *path);
bool			exists_file(const char *path);

/**********  Redirect **********/
void			set_redirect(t_process process, t_shell *msh);
void			reset_redirection(t_process process);
void			dup_redirect(t_process process, t_shell *msh);

/**********  Process **********/
pid_t			create_child_process(t_shell *msh);
void			wait_all_child_processes(t_shell *msh);
void			wait_child_process(pid_t pid);

/********** Pipeline **********/
t_pipe			init_pipeline(size_t cnt);
void			set_pipeline(t_pipe pipes);
void			delete_pipeline(t_pipe pipes);

/********** I/O utils **********/
int				xdup(int new_fd);
void			xdup2(int old_fd, int new_fd);
void			xclose(int fd);
void			xpipe(int fds[2]);
void			dup_and_close(int old_fd, int new_fd);

#endif