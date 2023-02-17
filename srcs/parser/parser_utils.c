/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:19:13 by event             #+#    #+#             */
/*   Updated: 2023/02/04 16:23:45 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief 解析対象のインデックスを次に進める。
 *
 * @param tokens
 * @param curr
 */
void	next_token(t_vector *tokens, t_token **curr)
{
	t_token	*next;

	next = (t_token *)ft_vector_next(tokens, *curr, 1);
	if (!next)
		exit(0);
	*curr = next;
}

/**
 * @brief 解析対象の文字を取得し、インデックスを次に進める。
 *
 * @param tokens トークンのリスト
 * @param toketype　判定したいトークンの種別　
 * @param curr　現在解析しているトークン
 * @param buff　正であればbuffにトークンの文字列を書き込む
 * @return true
 * @return false
 */
char	*scan_token(t_vector *tokens, t_token **curr)
{
	char	*buff;

	if (!curr || !*curr || (*curr)->type & TOKEN_END)
		return (NULL);
	buff = ft_strdup((*curr)->data);
	if (!buff)
		return (NULL);
	next_token(tokens, curr);
	return (buff);
}
