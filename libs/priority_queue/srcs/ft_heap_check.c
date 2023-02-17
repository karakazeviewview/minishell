/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:22:44 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/20 10:22:44 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"

bool	ft_heap_is_full(t_heap *heap)
{
	if (heap->cap < heap->end)
		return (true);
	return (false);
}

bool	ft_heap_is_empty(t_heap *heap)
{
	if (heap->end <= 1)
		return (true);
	return (false);
}

size_t	ft_heap_size(t_heap *heap)
{
	if (heap->end == 1)
		return (0);
	return (heap->end - 1);
}
