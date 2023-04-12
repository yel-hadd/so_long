/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:25:46 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 22:39:44 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*
get map line by its index
returns NULL if not found
*/

char    *get_line(t_list *node, int index)
{
	while (node != NULL)
	{
		if (node->index == index)
			return (node->line);
		node = node->next;
	}
	return (NULL);
}
