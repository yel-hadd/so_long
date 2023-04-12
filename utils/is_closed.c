/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:59:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 22:05:59 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	is_closed(t_list *ptr)
{
	t_list	*map;

	map = ptr;
	if (!all_ones(map->line) || !all_ones(ft_lstlast(map)->line))
		return (0);
	if (!starts_ends_1(map))
		return (0);
	return (1);
}
