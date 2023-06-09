/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_invalid_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:00:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 00:37:02 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	has_invalid_char(t_map *node)
{
	int		i;
	char	c;
	char	*str;

	i = 0;
	while (node != NULL)
	{
		str = node->line;
		i = 0;
		while (str[i] != '\0')
		{
			c = str[i];
			if (c != 'P' && c != 'C' && c != '0' && c != '1' && c != 'E')
				return (1);
			i ++;
		}
		node = node->next;
	}
	return (0);
}
