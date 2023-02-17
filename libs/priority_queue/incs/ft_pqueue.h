/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqueue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:47:47 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:47:47 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PQUEUE_H
# define FT_PQUEUE_H

# define PQUEUE_SUCCESS 1
# define PQUEUE_FAILURE 0

# include <stdbool.h>
# include "ft_heap.h"

typedef struct s_pqueue {
	t_heap	*heap;
}	t_pqueue;

// ********** Constructor ********** //
t_pqueue	*ft_priority_queue_init(size_t cap,
				int (*cmp)(const void *, const void *));

// ********** Deconstructor ********** //
void		ft_priority_queue_delete(t_pqueue **queue, void (*del)(void *));

// ********** Modifier ********** //
int			ft_priority_queue_push(t_pqueue *queue, void *data);
int			ft_priority_queue_pop(t_pqueue *queue, void **data);

// ********** Other Utils ********** //
bool		ft_priority_queue_empty(t_pqueue *queue);
bool		ft_priority_queue_is_empty(t_pqueue *queue);
size_t		ft_priority_queue_size(t_pqueue *queue);
#endif