/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:00 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/04 17:12:23 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct map
{
	char			*line;
	struct map	*next;
}	t_list;

char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_calloc(size_t count, size_t size);
int		get_next_line(int fd, char **res);
char	*ft_strjoin(char *s1, char *s2);
t_list	*new_map_line(char *line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
t_list	*getmap(char *map_path);
char	*remove_nl(char *s1);
char	*ft_strdup(char *s1);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


#endif