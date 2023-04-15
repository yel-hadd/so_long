/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/15 00:01:42 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>

void	f(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_map		*copy;
	t_player	*p;
	(void) ac;

	if (ac != 2)
		return (1);
	map = getmap(av[1]);
	if (map == NULL || is_valid_map(&map) != 1)
	{
		printf("invalid map\n");
		return (1);
	}
	p = spawn_player(map);
	copy = ft_lstcopy(map);
	flood_fill(&copy, p->x, p->y);
	if (flood_check(&copy) != 1)
		printf("invalid map\n");
	else
		printf("valid map");
	ft_lstclear(&map);
	free(p);
	//atexit(f);
}
