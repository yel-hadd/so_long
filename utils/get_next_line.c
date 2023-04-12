/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:31:39 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/12 01:35:15 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	get_line_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	read_and_save(char **storage, int fd)
{
	char	*buf;
	long	read_byte;
	long	i;
	char	*tmp;

	read_byte = 1;
	i = 0;
	while (!ft_strchr(*storage, '\n'))
	{
		buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buf)
			return (free(*storage));
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(*storage), free(buf));
		if (read_byte == 0)
			return (free(buf));
		tmp = *storage;
		*storage = ft_strjoin(*storage, buf);
		free(buf);
		free(tmp);
	}
}

int	get_next_line(int fd, char **res)
{
	char		*line;
	static char	*storage;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	read_and_save(&storage, fd);
	if (!storage || !*storage)
		return (free(storage), -1);
	i = get_line_index(storage);
	line = ft_substr(storage, 0, i);
	if (!line)
		return (free(storage), -1);
	tmp = storage;
	storage = ft_substr(storage, i, ft_strlen(storage) - i);
	free(tmp);
	*res = line;
	return (1);
}
