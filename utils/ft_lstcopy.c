/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:49:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:52:58 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_list	*ft_lstcopy(t_list *lst)
{
	t_list  *copy;

	copy = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&copy, new_map_line(ft_strdup(lst->line), lst->index));
		lst = lst->next;
	}
	return (copy);
}
