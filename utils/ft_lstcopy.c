/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:49:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_map	*ft_lstcopy(t_map *lst)
{
	t_map  *copy;

	copy = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&copy, new_map_line(ft_strdup(lst->line), lst->index));
		lst = lst->next;
	}
	return (copy);
}
