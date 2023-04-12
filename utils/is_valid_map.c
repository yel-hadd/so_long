/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:58:46 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 21:59:03 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	is_valid_map(t_list **ptr)
{
	t_list	*map;

	map = *ptr;
	if (ft_lstsize(map) < 3 || has_invalid_char(map))
		return (-2);
	if (!is_closed(map) || block_count(map, 'E') != 1)
		return (-3);
	if (block_count(map, 'C') < 1 || block_count(map, 'P') != 1)
		return (-4);
	return (1);
}
