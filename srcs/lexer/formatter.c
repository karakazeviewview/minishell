/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:05:09 by event             #+#    #+#             */
/*   Updated: 2023/02/04 16:43:57 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

void	format_space(t_token *token)
{
	char	*formatted;

	if (!token || !token->data)
		return ;
	formatted = ft_strtrim(token->data, " ");
	if (!formatted)
		exit(EXIT_FAILURE);
	free(token->data);
	token->data = formatted;
}
