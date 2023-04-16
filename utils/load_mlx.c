/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:59:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 23:54:36 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_mlx    *load_mlx(t_map *map, t_player *p, char *title)
{
	t_mlx		*node;
	int			x;
    int			y;

	node = (t_mlx *)malloc(sizeof(t_mlx));
	if (!node)
		return (node);
	x = ft_strlen(map->line) * 40;
	y = ft_lstsize(map) * 40;
	node->ptr = mlx_init();
	node->win = mlx_new_window(node->ptr, x, y, title);
	node->b = load_blocks(node->ptr);
	node->p = p;
	node->map = map;
    node->next = NULL;
	return (node);
}
