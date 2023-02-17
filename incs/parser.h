/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:21:31 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/11 22:49:08 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libast.h"
# include "libft.h"
# include "ft_vector.h"
# include "ft_deque.h"
# include "terminal.h"

void		parser(t_vector *tokens, t_ast_node **node, t_shell *msh);
t_ast_node	*parse_command_line(t_vector *tokens, t_token **curr);
t_ast_node	*parse_pipeline(t_vector *tokens, t_token **curr);
t_argument	*parse_argument(t_vector *tokens, t_token **curr);
t_ast_node	*parse_simple_cmd(t_vector *tokens, t_token **curr);
t_redirect	*parse_io_redirect(t_vector *tokens, t_token **curr);
t_ast_node	*parse_command(t_vector *tokens, t_token **curr);
char		*scan_token(t_vector *tokens, t_token **curr);
void		next_token(t_vector *tokens, t_token **curr);

#endif