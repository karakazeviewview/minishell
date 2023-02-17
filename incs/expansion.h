/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:19:26 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:34:57 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# define FTWRDE_SUCCESS 0
# define FTWRDE_BADCHAR 1
# define FTWRDE_BADVAL 2
# define FTWRDE_CMDSUB 3
# define FTWRDE_NOSPACE 4
# define FTWRDE_SYNTAX 5

# include "libast.h"
# include "terminal.h"

typedef struct s_wordexp {
	char		**buff;
	size_t		act_len;
	size_t		max_len;
	t_hashmap	*envs;
}	t_wordexp;

void		expander(t_ast_node *syntax_tree, t_shell *msh);
void		expand_environs(t_command *command, t_hashmap *environ);
void		expand_heredoc(t_command *command);

int			ft_wordexp(char *words, char **buff, t_hashmap *environ);
int			we_parse_dollar(char *words, t_wordexp *wp, size_t *offset);
int			we_parse_quote(char *words, t_wordexp *wp, size_t *offset);
int			we_parse_params(char *words, t_wordexp *wp, size_t *offset);

t_wordexp	we_newword(char **buff, t_hashmap *environs);
void		we_addstr(t_wordexp *wp, const char *str);
void		we_addchar(t_wordexp *wp, char ch);

int			heredoc_redirect(char *here_end, t_shell *msh);

#endif