/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:55:52 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 00:31:04 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	draw_map(void *ml, void *win, t_map *map, t_blocks *blocks)
{
	char	*line;
	int		i;
	int		y;

	while (map != NULL)
	{
		line = map->line;
		y = map->index * 40;
		i = -1;
		while (line[++ i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(ml, win, blocks->w, i * 40, y);
			else if (line[i] == '0' || line[i] == 'E')
				mlx_put_image_to_window(ml, win, blocks->o, i * 40, y);
			else if (line[i] == 'C')
				mlx_put_image_to_window(ml, win, blocks->c, i * 40, y);
			else if (line[i] == 'P')
				mlx_put_image_to_window(ml, win, blocks->pl, i * 40, y);
		}
		map = map->next;
	}
}
