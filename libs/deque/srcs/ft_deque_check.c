/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_is_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:39:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 10:39:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

bool	ft_deque_is_full(t_deque *deque)
{
	if (deque->len == deque->cap)
		return (true);
	return (false);
}

bool	ft_deque_is_empty(t_deque *deque)
{
	if (deque->len == 0)
		return (true);
	return (false);
}

size_t	ft_deque_size(t_deque *deque)
{
	return (deque->len);
}
