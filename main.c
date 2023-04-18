/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 14:54:29 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_hook(int key, t_mlx *game)
{
	if (key == 13 || key == 126)
		move_up(game);
	else if (key == 0 || key == 123)
		move_left(game);
	else if (key == 1 || key == 125)
		move_down(game);
	else if (key == 2 || key == 124)
		move_right(game);
	else if (key == 53)
		exit(0);
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
}
