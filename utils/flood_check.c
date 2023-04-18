/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:50:43 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 00:35:10 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	flood_check(t_map **lst)
{
	t_map	*node;
	int		i;
	char	*str;

	node = *lst;
	while (node != NULL)
	{
		i = -1;
		while (node->line[++i])
		{
			str = node->line;
			if (str[i] != '1' && str[i] != 'X' && str[i] != '0')
			{
				printf("%d\n", str[i]);
				return (ft_lstclear(lst), 0);
			}
		}
		node = node->next;
	}
	return (ft_lstclear(lst), 1);
}
