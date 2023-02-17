/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 23:04:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

#define INIT_NBITS 16

size_t	default_hash(const void	*data)
{
	return ((size_t)data);
}

t_hashmap	*ft_hashmap_init(size_t(*hash)(const void *data), \
	void(*destr)(void *))
{
	t_hashmap	*new_map;

	new_map = malloc(sizeof(t_hashmap));
	if (!new_map)
		return (NULL);
	new_map->nbits = INIT_NBITS;
	new_map->cap = (size_t)(1 << new_map ->nbits);
	new_map->mask = new_map->cap - 1;
	if (!hash)
		new_map->hash = hashmap_hash_int;
	else
		new_map->hash = hash;
	if (!destr)
		new_map->destr = free;
	else
		new_map->destr = destr;
	new_map->data = malloc(sizeof(t_hashmap_data) * new_map->cap);
	if (!new_map->data)
	{
		free(new_map);
		return (NULL);
	}
	ft_hashmap_clear(new_map);
	return (new_map);
}
