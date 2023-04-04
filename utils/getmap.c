/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:10:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/04 17:11:00 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_list	*getmap(char	*map_path)
{
	int		mapfd;
	t_list	*map;
	char	*line;
	int		i;

	map = NULL;
	mapfd = open(map_path, O_RDONLY);
	i = -1;
	while (get_next_line(mapfd, &line) > 0)
    {
        if (++ i == 0)
			map = new_map_line(remove_nl(line));
		else
			ft_lstadd_back(&map, new_map_line(remove_nl(line)));
        free(line);
    }
	close(mapfd);
	return (map);
}
