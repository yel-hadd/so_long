/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 02:40:27 by yel-hadd         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map		*map;
	t_map		*copy;
	t_player	*p;
	t_blocks	*b;
	void		*ml;
	void		*win;

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
	ml = mlx_init();
	win = mlx_new_window(ml, ft_strlen(map->line) * 40, (ft_lstlast(map)->index + 1) * 40, "SAAD");
	b = load_blocks(ml);
	draw_map(ml, win, map, b);
	mlx_loop(ml);
	free(ml);
	ft_lstclear(&map);
	free(p);
	//atexit(f);
}
