/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:25:27 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 15:31:10 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	move_right(t_mlx *game)
{
	int			x;
	int			y;
	t_player	*pl;
	t_blocks	*bl;
	t_map		*map;

	map = game->map;
	pl = game->p;
	bl = game->b;
	x = pl->x;
	y = pl->y;
	if (block_is_wall(game->map, x + 1, y))
		return ;
	ft_putnbr_fd(++ game->move, 1);
	write(1, "\n", 1);
	if (block_is_coin(game->map, x + 1, y))
		pl->collected += 1;
	if (pl->collected == map->coins)
		mlx_put_image_to_window(game->ptr, game->win, bl->e, \
		game->exit[0] * 40, game->exit[1] * 40);
	mlx_put_image_to_window(game->ptr, game->win, bl->o, x * 40, y * 40);
	pl->x += 1;
	mlx_put_image_to_window(game->ptr, game->win, bl->pr, (x + 1) * 40, y * 40);
	if (block_is_exit(game->map, pl->x, pl->y) && pl->collected == map->coins)
		safe_exit_wrap(game);
}
