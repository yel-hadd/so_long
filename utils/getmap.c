/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:10:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 22:14:23 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_list	*getmap(char	*map_path)
{
	int		mapfd;
	t_list	*map;
	char	*line;
	char	*tmp;
	int		i;

	map = NULL;
	mapfd = open(map_path, O_RDONLY);
	i = -1;
	while (get_next_line(mapfd, &line) > 0)
	{
		tmp = line;
		ft_lstadd_back(&map, new_map_line(ft_strtrim(line, "\n"), ++ i));
		free(tmp);
	}
	close(mapfd);
	return (map);
}
