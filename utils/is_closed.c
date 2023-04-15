/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:59:21 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	is_closed(t_map *ptr)
{
	t_map	*map;

	map = ptr;
	if (!all_ones(map->line) || !all_ones(ft_lstlast(map)->line))
		return (0);
	if (!starts_ends_1(map))
		return (0);
	return (1);
}
