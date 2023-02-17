/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:26:57 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/12 14:26:57 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
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
