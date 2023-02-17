/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqueue_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 06:53:30 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 06:53:30 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"
#include "ft_pqueue.h"

int	ft_priority_queue_push(t_pqueue *queue, void *data)
{
	if (ft_heap_push(queue->heap, data) == HEAP_FAILURE)
		return (PQUEUE_FAILURE);
	return (PQUEUE_SUCCESS);
}

int	ft_priority_queue_pop(t_pqueue *queue, void **data)
{
	if (ft_heap_pop(queue->heap, data) == HEAP_FAILURE)
		return (PQUEUE_FAILURE);
	return (PQUEUE_SUCCESS);
}
