/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:55:38 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks a.out");
}

int	flood_check(t_list **lst)
{
	t_list	*
	return (ft_lstclear(lst), 1);
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

	//atexit(f);
}
