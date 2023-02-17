/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:29:45 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/19 23:29:45 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"

static void	swap(t_heap *heap, const int i1, const int i2)
{
	void	*tmp;

	tmp = heap->data[i1];
	heap->data[i1] = heap->data[i2];
	heap->data[i2] = tmp;
}

static void	up_heap(t_heap *heap, size_t index)
{
	size_t	parent;

	while (index > 1)
	{
		parent = index / 2;
		if (heap->cmp(heap->data[parent], heap->data[index]) == 1)
		{
			swap(heap, parent, index);
			index = parent;
		}
		else
			break ;
	}
}

static void	down_heap(t_heap *heap)
{
	size_t	index;
	size_t	child;

	index = 1;
	while (index * 2 <= heap->end)
	{
		child = index * 2;
		if (child + 1 < heap->end
			&& heap->cmp(heap->data[child], heap->data[child + 1]) == 1)
			child += 1;
		if (heap->cmp(heap->data[child], heap->data[index]) == -1)
		{
			swap(heap, child, index);
			index = child;
		}
		else
			break ;
	}
}

int	ft_heap_push(t_heap *heap, void *data)
{
	size_t	index;

	if (ft_heap_is_full(heap) == true)
	{
		if (ft_heap_realloc(heap) == HEAP_FAILURE)
			return (HEAP_FAILURE);
	}
	index = heap->end;
	heap->data[index] = data;
	heap->end += 1;
	up_heap(heap, index);
	return (HEAP_SUCCESS);
}

int	ft_heap_pop(t_heap *heap, void **data)
{
	if (ft_heap_is_empty(heap) == true)
		return (HEAP_FAILURE);
	*data = heap->data[1];
	heap->end -= 1;
	heap->data[1] = heap->data[heap->end];
	down_heap(heap);
	return (HEAP_SUCCESS);
}
