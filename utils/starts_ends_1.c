/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts_ends_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:03:38 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:35:37 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	starts_ends_1(t_list *node)
{
	int		i;
	size_t	len;
	t_list	*last;

	i = -1;
	last = ft_lstlast(node);
	while (node != NULL)
	{
		len = ft_strlen(node->line);
		if (node->line[0] != '1')
			return (0);
		else if (node->line[len - 1] != '1')
			return (0);
		node = node->next;
	}
	return (1);
}
