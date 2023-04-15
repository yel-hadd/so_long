/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:58:46 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 23:26:43 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	is_valid_map(t_map **ptr)
{
	t_map	*map;

	map = *ptr;
	if (ft_lstsize(map) < 3 || has_invalid_char(map))
		return (-2);
	if (!is_closed(map) || block_count(map, 'E') != 1)
		return (-3);
	if (block_count(map, 'C') < 1 || block_count(map, 'P') != 1)
		return (-4);
	if (!same_len(map))
		return (-5);
	return (1);
}
