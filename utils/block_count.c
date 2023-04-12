/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:04:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 22:05:05 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	block_count(t_list *node, char block)
{
	int		i;
	char	*str;
	int		count;

	count = 0;
	while (node != NULL)
	{
		i = 0;
		str = node->line;
		while (str[i])
		{
			if (str[i] == block)
				count += 1;
			i ++;
		}
		node = node->next;
	}
	return (count);
}
