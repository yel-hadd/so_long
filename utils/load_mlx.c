/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:59:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 16:59:33 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_mlx    *load_mlx(t_map *map, char *title)
{
	t_mlx	*b;
	int			x;
    int			y;

	b = (t_mlx *)malloc(sizeof(t_mlx));
	if (!b)
		return (b);
	x = ft_strlen(map->line) * 40;
	y = ft_lstsize(map) * 40;
	b->ptr = mlx_init();
	b->win = mlx_new_window(b->ptr, x, y, title);
    b->next = NULL;
	return (b);
}
