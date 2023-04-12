/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:49:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 00:59:07 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_list  *ft_lstcopy(t_list *lst)
{
    t_list  *new;
    t_list  *node;

    while (lst != NULL)
    {
        node = new_map_line(ft_strdup(lst->line), lst->index);
        ft_lstadd_back(&new, node);
        lst = lst->next;
    }
    return (new);
}
