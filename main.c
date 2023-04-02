/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/02 16:55:13 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_list	*map;
	int		mapfd;

	mapfd = open(av[1], O_RDONLY);
	map = new_map_line(get_next_line(mapfd));
	while (map->line != NULL)
	{
		printf("%s", map->line);
		free(str);
		str = get_next_line(mapfd);
	}
}
