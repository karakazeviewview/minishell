/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_bound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:05:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/06 19:05:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_lower_bound(int *arr, int n, int x)
{
	int	mid;
	int	lo;
	int	hi;

	lo = 0;
	hi = n;
	while (lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (x <= arr[mid])
			hi = mid;
		else
			lo = mid + 1;
	}
	return (&arr[lo]);
}
