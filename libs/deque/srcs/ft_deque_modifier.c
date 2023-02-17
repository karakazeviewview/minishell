/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:44:18 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 17:44:18 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cast_d;
	unsigned char	*cast_s;

	if (!dst && !src)
		return (NULL);
	cast_d = (unsigned char *)dst;
	cast_s = (unsigned char *)src;
	while (n--)
		*(cast_d++) = *(cast_s++);
	return (dst);
}

int	ft_deque_pop_front(t_deque *deque, void *data)
{
	if (ft_deque_is_empty(deque) == true)
		return (DEQUE_FAILURE);
	ft_memcpy(data, deque->begin, deque->data_size);
	deque->begin = ft_deque_next(deque, deque->begin, 1);
	deque->len -= 1;
	return (DEQUE_SUCCESS);
}

int	ft_deque_pop_back(t_deque *deque, void *data)
{
	if (ft_deque_is_empty(deque) == true)
		return (DEQUE_FAILURE);
	ft_memcpy(data, ft_deque_back(deque), deque->data_size);
	deque->end = ft_deque_prev(deque, deque->end, 1);
	deque->len -= 1;
	return (DEQUE_SUCCESS);
}

int	ft_deque_push_front(t_deque *deque, const void *data)
{
	if (ft_deque_is_full(deque) == true)
	{
		if (ft_deque_realloc(deque) == DEQUE_FAILURE)
			return (DEQUE_FAILURE);
	}
	deque->begin = ft_deque_prev(deque, deque->begin, 1);
	ft_memcpy(deque->begin, data, deque->data_size);
	deque->len += 1;
	return (DEQUE_SUCCESS);
}

int	ft_deque_push_back(t_deque *deque, const void *data)
{
	if (ft_deque_is_full(deque) == true)
	{
		if (ft_deque_realloc(deque) == DEQUE_FAILURE)
			return (DEQUE_FAILURE);
	}
	ft_memcpy(deque->end, data, deque->data_size);
	deque->end = ft_deque_next(deque, deque->end, 1);
	deque->len += 1;
	return (DEQUE_SUCCESS);
}
