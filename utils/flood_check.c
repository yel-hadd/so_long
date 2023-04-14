/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:50:43 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 20:50:55 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	flood_check(t_list **lst)
{
	t_list	*node;
	int		i;

	node = *lst;
	while (node != NULL)
	{
		i = -1;
		while(node->line[++i])
		{
			if (node->line[i] != '1' && node->line[i] != 'X')
				return (ft_lstclear(lst), 0);
		}
		node = node->next;
	}
	return (ft_lstclear(lst), 1);
}
