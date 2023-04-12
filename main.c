/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:33:18 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks a.out");
}

t_player	*spawn_player(t_list *map)
{
	t_player	*ptr;

	ptr = (t_player *)malloc(sizeof(t_player));
	if (!ptr)
		return (ptr);

	ptr->x = get_player_pos(map, 0);
	ptr->y = get_player_pos(map, 1);
	ptr->next = NULL;
	return (ptr);
}

int	main(int ac, char **av)
{
	t_list		*map;
	t_player	*p;
	(void) ac;

	map = getmap(av[1]);
	if (is_valid_map(&map) != 1)
		return (0);
	p = spawn_player(map);
	flood_fill(&map, p->x, p->y);
	//printf("--%c\n", get_line(map, p->y)[p->x]);
	while (map!= NULL)
	{
		printf("%s\n", map->line);
		map = map->next;
	}
	//atexit(f);
}
