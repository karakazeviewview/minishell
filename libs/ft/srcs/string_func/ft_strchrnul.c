/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:27:39 by tmuramat          #+#    #+#             */
/*   Updated: 2023/01/02 19:28:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrnul(const char *s, int c)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (1)
	{
		if (*cast_s == (char)c)
			return (cast_s);
		if (*cast_s == '\0')
			break ;
		cast_s++;
	}
	return (cast_s);
}
