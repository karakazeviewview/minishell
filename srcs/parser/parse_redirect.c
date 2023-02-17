/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:08 by event             #+#    #+#             */
/*   Updated: 2023/02/11 22:51:59 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse_redirection.c
 * @brief 構文解析その3：リダイレクト ">, >>, <, <<"
 * @date 2023-01-01
 */
#include "parser.h"

/**
 * @note
 * [BNF]
 * <io_redirect>	::= '>'  filename
 *					| 	'>>' filename
 *					| 	'<'  filename
 *					| 	'<<' here_end
 * [EBNF]
 * io_redirect		::= ('>' | '>>' | '<' | '<<') word
 */

/**
 * @brief リダイレクの解析
 *
 * @param tokens
 * @param curr
 * @return t_redirect* リダイレクトの管理情報
 */
t_redirect	*parse_io_redirect(t_vector *tokens, t_token **curr)
{
	int		dir;
	int		fd;
	char	*file;

	fd = 0;
	dir = NODE_NONE;
	if ((*curr)->type & TOKEN_RDIR_HEREDOC)
		dir = NODE_RDIR_HEREDOC;
	else if ((*curr)->type & TOKEN_RDIR_INPUT)
		dir = NODE_RDIR_INPUT;
	else if ((*curr)->type & TOKEN_RDIR_OUTPUT)
	{
		fd = 1;
		dir = NODE_RDIR_OUTPUT;
	}
	else if ((*curr)->type & TOKEN_RDIR_APPEND)
	{
		fd = 1;
		dir = NODE_RDIR_APPEND;
	}
	next_token(tokens, curr);
	file = scan_token(tokens, curr);
	return (ast_redirect_create(dir, fd, file));
}
