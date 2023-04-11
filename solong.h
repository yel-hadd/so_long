/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:00 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/11 00:38:53 by yel-hadd         ###   ########.fr       */
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
char	*ft_strtrim(char *s1, char *set);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
t_list	*new_map_line(char *line);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*getmap(char *map_path);
int		ft_lstsize(t_list *lst);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


#endif