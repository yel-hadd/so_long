/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:48:46 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_map	*new_map_line(char *line, int index)
{
	t_map	*ptr;

	ptr = (t_map *)malloc(sizeof(t_map));
	if (!ptr)
		return (ptr);
	ptr->line = line;
	ptr->index = index;
	ptr->next = NULL;
	return (ptr);
}
