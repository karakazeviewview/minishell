/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:56:23 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 15:56:23 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vector_front(t_vector *vector)
{
	if (ft_vector_is_empty(vector) == true)
		return (NULL);
	return (vector->data);
}

void	*ft_vector_back(t_vector *vector)
{
	void	*itr;

	if (ft_vector_is_empty(vector) == true)
		return (NULL);
	itr = (char *)vector->end - vector->data_size;
	return (itr);
}

void	*ft_vector_next(t_vector *vector, void *it, size_t n)
{
	size_t	offset;

	offset = ((char *)it - (char *)vector->data) / vector->data_size;
	offset += n;
	if (offset > vector->len)
		return (NULL);
	it = (char *)vector->data + offset * vector->data_size;
	return (it);
}

void	ft_vector_foreach(t_vector *vector, void (*func)(void *, void *), \
			void *item)
{
	void	*itr;
	size_t	len;

	itr = vector->data;
	len = vector->len;
	while (len--)
	{
		func(itr, item);
		itr = (char *)itr + vector->data_size;
	}
}
