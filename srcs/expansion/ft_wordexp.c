/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:34:43 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/12 14:40:12 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_wordexp.c
 * @brief
 * @date 2023-02-12
 */

#include "expansion.h"

/**
 * @brief シェルの文法に従って文字列を展開する。
 *
 * @detail 環境変数の展開のみ実装
 * @param word　展開元となる文字列
 * @param buff 展開された文字列が格納されるアドレス
 * @param environ　展開に使用する環境変数
 * @return int 成功した場合は0を返す。構文エラーの場合は対応する値を返す。
 */
int	ft_wordexp(char *words, char **buff, t_hashmap *environs)
{
	size_t		offset;
	t_wordexp	we;

	if (!words)
		return (FTWRDE_SYNTAX);
	we = we_newword(buff, environs);
	offset = 0;
	while (words[offset])
	{
		if (words[offset] == '$')
		{
			++offset;
			we_parse_dollar(words, &we, &offset);
		}
		else if (words[offset] == '\'' || words[offset] == '"')
		{
			++offset;
			we_parse_quote(words, &we, &offset);
		}
		else
			we_addchar(&we, words[offset++]);
	}
	*buff = *we.buff;
	return (FTWRDE_SUCCESS);
}
