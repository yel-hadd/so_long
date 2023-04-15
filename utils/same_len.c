/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:24:35 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/15 00:12:14 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	same_len(t_map *node)
{
	int	len;

	len = ft_strlen(node->line);
	while (node != NULL)
	{
		if (ft_strlen(node->line) != len)
			return (0);
		node = node->next;
	}
	return (1);
}
