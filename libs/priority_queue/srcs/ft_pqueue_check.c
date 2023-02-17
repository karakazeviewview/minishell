/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqueue_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 06:55:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 06:55:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"
#include "ft_pqueue.h"

bool	ft_priority_queue_is_empty(t_pqueue *queue)
{
	if (ft_heap_is_empty(queue->heap) == true)
		return (true);
	return (false);
}

size_t	ft_priority_queue_size(t_pqueue *queue)
{
	return (ft_heap_size(queue->heap));
}
