/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:55:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 15:55:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	ft_vector_is_full(t_vector *vector)
{
	if (vector->len == vector->cap)
		return (true);
	return (false);
}

bool	ft_vector_is_empty(t_vector *vector)
{
	if (vector->len == 0)
		return (true);
	return (false);
}

size_t	ft_vector_size(t_vector *vector)
{
	return (vector->len);
}
