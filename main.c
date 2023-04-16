/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 17:27:03 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks solong");
}

void	draw_map(void *ml, void *win, t_map *map, t_blocks *blocks)
{
	char	*line;
	int		i;
	int		x;

	while (map != NULL)
	{
		line = map->line;
		x = map->index;
		i = -1;
		while (line[++ i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(ml, win, blocks->W, i * 40, x * 40);
			else if (line[i] == '0' || line[i] == 'E')
				mlx_put_image_to_window(ml, win, blocks->O, i * 40, x * 40);
			else if (line[i] == 'C')
				mlx_put_image_to_window(ml, win, blocks->C, i * 40, x * 40);
			else if (line[i] == 'P')
				mlx_put_image_to_window(ml, win, blocks->P, i * 40, x * 40);
		}
		map = map->next;
	}
}

void	start_game(t_map *map, t_player *p, t_blocks *b, t_mlx *m)
{
	draw_map(m->ptr, m->win, map, b);
	mlx_loop(m->ptr);
	free_mlx(&m);
	ft_lstclear(&map);
	free(p);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_map		*copy;
	t_player	*p;
	t_blocks	*b;
	t_mlx		*m;

	if (ac != 2)
		return (1);
	map = getmap(av[1]);
	if (map == NULL || is_valid_map(&map) != 1)
		return (ft_lstclear(&map), 1);
	p = spawn_player(map);
	copy = ft_lstcopy(map);
	flood_fill(&copy, p->x, p->y);
	if (flood_check(&copy) != 1)
		return (ft_lstclear(&map), free(p), 1);
	m = load_mlx(map, "SAAD");
	b = load_blocks(m->ptr);
	start_game(map, p, b, m);
	//atexit(f);
}
