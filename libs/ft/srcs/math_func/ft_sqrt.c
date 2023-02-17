/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:29:34 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 01:29:34 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static double	sqrt_fractorial(double ans, int x)
{
	double	inc;
	int		i;

	inc = 0.1;
	i = 0;
	while (i < 5)
	{
		while (ans * ans <= x)
			ans += inc;
		ans = ans - inc;
		inc = inc / 10;
		i++;
	}
	return (ans);
}

double	ft_sqrt(double x)
{
	int	lo;
	int	hi;
	int	mid;
	int	ans;

	lo = 0;
	hi = x;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == x)
		{
			ans = mid;
			break ;
		}
		else if (mid * mid < x)
		{
			ans = lo;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	return (sqrt_fractorial(ans, x));
}
