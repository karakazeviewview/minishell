/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_realoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:16:05 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/11 10:16:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	ft_deque_clear(t_deque *deque)
{
	deque->begin = deque->data;
	deque->end = deque->data;
	deque->len = 0;
}

void	ft_deque_delete(t_deque **deque)
{
	free((*deque)->data);
	(*deque)->data = NULL;
	free((*deque));
	*deque = NULL;
}
