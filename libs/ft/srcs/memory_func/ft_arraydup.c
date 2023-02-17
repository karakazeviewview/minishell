/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:05:05 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/07 09:05:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arraydup(int const *src, size_t len)
{
	int	*p;

	p = (int *)malloc(len * sizeof(int));
	if (!p)
		return (NULL);
	ft_memmove(p, src, len * sizeof(int));
	return (p);
}
