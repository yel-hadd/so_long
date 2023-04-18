/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:04:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/17 21:50:04 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	block_count(t_map *node, char block)
{
	int		i;
	char	*str;
	int		count;
	t_map	*copy;

	count = 0;
	copy = node;
	while (node != NULL)
	{
		i = 0;
		str = node->line;
		while (str[i])
		{
			if (str[i] == 'E')
			{
				copy->exit[0] = i;
				copy->exit[1] = node->index;
			}
			if (str[i] == block)
				count += 1;
			i ++;
		}
		node = node->next;
	}
	return (count);
}
