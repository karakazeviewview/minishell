/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:19:46 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 22:19:46 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"

void	ft_hashmap_clear(t_hashmap *map)
{
	ft_memset(map->data, 0, sizeof(t_hashmap_data) * map->cap);
	map->len = 0;
}

void	ft_hashmap_delete(t_hashmap **map)
{
	if (!*map)
		return ;
	free((*map)->data);
	(*map)->data = NULL;
	free(*map);
	(*map) = NULL;
}
