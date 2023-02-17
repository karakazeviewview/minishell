/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:16:31 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/12 08:23:02 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t	len;

	len = 0;
	while (*s1 != '\0')
	{
		if (ft_strchr(s2, *s1) == NULL)
			break ;
		s1++;
		len++;
	}
	return (len);
}
