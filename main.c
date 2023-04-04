/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/04 18:45:06 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks a.out");
}

int	all_ones(char *strig)
{
	int	i;

	i = -1;
	while (strig[++ i])
	{
		if (string[i] != '1')
			return (0);
	}
	return (1);
}

int	starts_ends_1(t_list *node)
{
	t_list	*node;
	int	i;

	i = -1;
	while (node != NULL)
	{
		if (node->line[0] != '1')
			return (0);
		if (node->line[-1] != '1')
			return (0);
		node = node->next
	}
	return (1);
}

int is_closed(t_list *ptr)
{
	t_list	*map;
	t_list	*head;

	map = ptr;
	if (!all_ones(map->line) || !all_ones(ft_lstlast(map)->line))
		return (0);
	if (!starts_ends_1(map))
		return (0);
	return (1);
}

int	is_valid_map(t_list **ptr)
{
	t_list	*map;
	t_list	*head;

	map = *ptr;
	if (ft_lstsize(*ptr) <= 3)
		return (0);
	if (!is_closed(&map))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*map;

	map = getmap(av[1]);
	while (map != NULL)
	{
		printf("%s\n", map->line);
		map = map->next;
	}
	//atexit(f);
}
