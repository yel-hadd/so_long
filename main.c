/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/16 23:55:25 by yel-hadd         ###   ########.fr       */
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
	int		y;

	while (map != NULL)
	{
		line = map->line;
		y = map->index * 40;
		i = -1;
		while (line[++ i])
		{
			if (line[i] == '1')
				mlx_put_image_to_window(ml, win, blocks->W, i * 40, y);
			else if (line[i] == '0' || line[i] == 'E')
				mlx_put_image_to_window(ml, win, blocks->O, i * 40, y);
			else if (line[i] == 'C')
				mlx_put_image_to_window(ml, win, blocks->C, i * 40, y);
			else if (line[i] == 'P')
				mlx_put_image_to_window(ml, win, blocks->PL, i * 40, y);
		}
		map = map->next;
	}
}

/*
W => 13
A => 0
S => 1
D => 2
ESC => 53
*/


int	key_hook(int keycode, t_mlx *m)
{
	printf("%d\n", keycode);
	printf("%s\n", m->map->line);
	return (0);
}

void	start_game(t_mlx *game)
{
	draw_map(game->ptr, game->win, game->map, game->b);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->ptr);
	free_mlx(&game);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_map		*copy;
	t_player	*p;
	t_mlx		*game;

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
	game = load_mlx(map, p, "SAAD");
	start_game(game);
	//atexit(f);
}
