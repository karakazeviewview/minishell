/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:47:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/25 00:47:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

static void	_hash_reinsert(t_hashmap *map, t_hashmap_data *new_data,
	t_hashmap_data data)
{
	size_t	i;
	size_t	hashed_key;

	hashed_key = map->hash(data.key);
	i = map->mask & (hashed_key * PRIME_1);
	while (new_data[i].value != 0)
	{
		if (ft_strcmp(new_data[i].key, data.key) == 0)
			return ;
		i = map->mask & (i + PRIME_2);
	}
	map->len += 1;
	new_data[i] = data;
}

int	ft_hashmap_resize(t_hashmap *map)
{
	t_hashmap_data	*new_data;
	size_t			prev_cap;
	size_t			i;

	prev_cap = map->cap;
	map->nbits += 1;
	map->cap = (size_t)(1 << map->nbits);
	map->mask = map->cap - 1;
	new_data = malloc(sizeof(size_t) * map->cap);
	if (!new_data)
		return (HASHMAP_FAILURE);
	ft_memset(new_data, 0, sizeof(t_hashmap_data) * map->cap);
	map->len = 0;
	i = 0;
	while (i < prev_cap)
	{
		_hash_reinsert(map, new_data, map->data[i]);
		i++;
	}
	free(map->data);
	map->data = new_data;
	return (HASHMAP_SUCCESS);
}
