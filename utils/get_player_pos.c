/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:57:55 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*
if choice == 0 returns x coordinate of player
if choice == 1 returns y coordinate of player
*/

int	get_player_pos(t_map *node, int choice)
{
	int		i;
	char	*str;

	while (node != NULL)
	{
		i = 0;
		str = node->line;
		while (str[i])
		{
			if (str[i] == 'P' && choice == 0)
				return (i);
			if (str[i] == 'P' && choice == 1)
				return (node->index);
			i ++;
		}
		node = node->next;
	}
	return (-1);
}
