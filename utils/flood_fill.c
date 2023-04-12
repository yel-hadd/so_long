/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:32:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:33:32 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	flood_fill(t_list **lst, int x, int y)
{
	t_list	*m;
	char	*line;

	m = *lst;
	line = get_line(m, y);
	if (line == NULL)
		return ;
	if (y >= ft_lstsize(m) || x >= ft_strlen(line))
		return ;
	if (line[x] == '1' || line[x] == 'X' )
		return ;
	line[x] = 'X';
	flood_fill(lst, x + 1, y);
	flood_fill(lst, x - 1, y);
	flood_fill(lst, x, y + 1);
	flood_fill(lst, x, y - 1);
	return ;
}
