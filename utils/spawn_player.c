/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:37:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_player	*spawn_player(t_map *map)
{
	t_player	*ptr;

	ptr = (t_player *)malloc(sizeof(t_player));
	if (!ptr)
		return (ptr);

	ptr->x = get_player_pos(map, 0);
	ptr->y = get_player_pos(map, 1);
	ptr->next = NULL;
    if (ptr->x == -1 || ptr->y == -1)
        return (free(ptr), NULL);
	return (ptr);
}
