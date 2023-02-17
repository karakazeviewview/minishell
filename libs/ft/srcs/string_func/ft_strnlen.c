/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:45:01 by tmuramat          #+#    #+#             */
/*   Updated: 2022/12/22 22:48:19 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (*c++ != '\0')
		cnt += 1;
	if (n < cnt)
		return (n);
	return (cnt);
}
