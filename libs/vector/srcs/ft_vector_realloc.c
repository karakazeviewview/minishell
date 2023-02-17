/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:56:46 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 15:56:46 by tmuramat         ###   ########.fr       */
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

static void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (NULL);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy (new_ptr, ptr, size);
	free(ptr);
	ptr = new_ptr;
	return (ptr);
}

int	ft_vector_realloc(t_vector *vector)
{
	t_vector	*new_ptr;
	size_t		new_cap;

	new_cap = vector->cap * 2;
	new_ptr = ft_realloc(vector->data, vector->data_size * new_cap);
	if (!new_ptr)
		return (VECTOR_FAILURE);
	vector->data = new_ptr;
	vector->cap = new_cap;
	vector->end = (char *)vector->data + vector->len * vector->data_size;
	return (VECTOR_SUCCESS);
}
