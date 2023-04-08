/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:14 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/08 18:04:49 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	f(void)
{
	system("leaks a.out");
}

int	all_ones(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

int	starts_ends_1(t_list *node)
{
	int		i;
	size_t	len;
	t_list	*last;

	i = -1;
	last = ft_lstlast(node);
	while (node != NULL)
	{
		len = ft_strlen(node->line);
		if (node->line[0] != '1')
			return (0);
		else if (node->next == NULL && node->line[len - 2] != '1')
			return (0);
		else if (node->line[len - 1] != '1')
			return (0);
		node = node->next;
	}
	return (1);
}

int	has_invalid_char(t_list *node)
{
	int	i;
	char	c;
	char	*str;

	i = 0;
	while (node != NULL)
	{
		str = node->line;
		i = 0;
		while (str[i])
		{
			c = str[i];
			if (c != 'P' && c != 'C' && c != '0' && c != '1' && c != 'E')
				return (1);
			i ++;
		}
		node = node->next;
	}
	return (0);
}

int is_closed(t_list *ptr)
{
	t_list	*map;

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

	map = *ptr;
	if (has_invalid_char(map))
		return (-1);
	if (ft_lstsize(map) <= 3)
		return (-2);
	if (!is_closed(map))
		return (-3);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*map;
	(void) ac;

	map = getmap(av[1]);
	printf("%d\n", is_valid_map(&map));
	while (map != NULL)
	{
		printf("%s", map->line);
		map = map->next;
	}
	//atexit(f);
}
