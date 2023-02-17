/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:30:12 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 16:30:12 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

t_deque	*ft_deque_init(size_t data_size, size_t cap)
{
	t_deque	*new_deque;

	new_deque = malloc(sizeof(t_deque));
	if (!new_deque)
		return (NULL);
	new_deque->data = malloc(sizeof(data_size) * cap);
	if (!new_deque->data)
	{
		free(new_deque);
		return (NULL);
	}
	ft_deque_clear(new_deque);
	new_deque->cap = cap;
	new_deque->data_size = data_size;
	return (new_deque);
}
