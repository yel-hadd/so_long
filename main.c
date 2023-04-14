/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 20:51:38 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_list		*map;
	t_list		*copy;
	t_player	*p;
	(void) ac;

	map = getmap(av[1]);
	if (is_valid_map(&map) != 1)
		return (0);
	p = spawn_player(map);
	copy = ft_lstcopy(map);
	flood_fill(&copy, p->x, p->y);
	printf("%d\n", flood_check(&copy));
	ft_lstclear(&map);
	free(p);
	atexit(f);
}
