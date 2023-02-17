/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:22:02 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/01 23:36:26 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

int	ft_hashmap_find(t_hashmap *map, const char *key, void **arg)
{
	size_t	i;
	size_t	hashed_key;

	hashed_key = map->hash(key);
	i = map->mask & (hashed_key * PRIME_1);
	while (map->data[i].in_use == true)
	{
		if (ft_strcmp(map->data[i].key, key) == 0)
		{
			*arg = map->data[i].value;
			return (HASHMAP_SUCCESS);
		}
		else
			i = map->mask & (i + PRIME_2);
	}
	*arg = NULL;
	return (HASHMAP_FAILURE);
}
