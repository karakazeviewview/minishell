/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:17:10 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 14:17:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

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

int	ft_vector_pop_back(t_vector *vector, void *data)
{
	if (ft_vector_is_empty(vector) == true)
		return (VECTOR_FAILURE);
	vector->end -= vector->data_size;
	ft_memcpy(data, vector->end, vector->data_size);
	vector->len -= 1;
	return (VECTOR_SUCCESS);
}

int	ft_vector_push_back(t_vector *vector, const void *data)
{
	if (ft_vector_is_full(vector) == true)
	{
		if (ft_vector_realloc(vector) == VECTOR_FAILURE)
			return (VECTOR_FAILURE);
	}
	ft_memcpy(vector->end, data, vector->data_size);
	vector->end += vector->data_size;
	vector->len += 1;
	return (VECTOR_SUCCESS);
}
