/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:57:42 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/19 22:57:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H
# define FT_HEAP_H

# define HEAP_SUCCESS 1
# define HEAP_FAILURE 0

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "string.h"

typedef struct s_heap {
	void	**data;
	size_t	cap;
	size_t	end;
	int		(*cmp)(const void *, const void *);
}	t_heap;

t_heap	*ft_heap_init(size_t cap, int (*cmp)(const void *, const void *));
int		ft_heap_realloc(t_heap *heap);
void	ft_heap_delete(t_heap **heap, void (*del)(void *));
int		ft_heap_push(t_heap *heap, void *data);
int		ft_heap_pop(t_heap *heap, void **data);

bool	ft_heap_is_full(t_heap *heap);
bool	ft_heap_is_empty(t_heap *heap);
size_t	ft_heap_size(t_heap *heap);

#endif