/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:16:53 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 14:16:53 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*ft_vector_init(size_t data_size, size_t cap)
{
	t_vector	*new_vector;

	new_vector = malloc(sizeof(t_vector));
	if (!new_vector)
		return (NULL);
	new_vector->data = malloc(sizeof(data_size) * (cap));
	if (!new_vector->data)
	{
		free(new_vector);
		return (NULL);
	}
	ft_vector_clear(new_vector);
	new_vector->cap = cap;
	new_vector->data_size = data_size;
	return (new_vector);
}
