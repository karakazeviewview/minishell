/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:45:06 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/04 21:45:06 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t size)
{
	unsigned char	*cast_a;
	unsigned char	*cast_b;
	unsigned char	*a_end;
	unsigned char	tmp;

	if (sizeof(a) != sizeof(b))
		return ;
	cast_a = (unsigned char *)a;
	cast_b = (unsigned char *)b;
	a_end = a + size;
	while (cast_a < a_end)
	{
		tmp = *cast_a;
		*cast_a = *cast_b;
		*cast_b = tmp;
		cast_a++;
		cast_b++;
	}
}
