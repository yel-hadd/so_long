/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:00 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/14 21:10:51 by yel-hadd         ###   ########.fr       */
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
	int				index;
	struct map		*next;
}	t_list;

typedef struct player
{
	int			x;
	int			y;
	struct map	*next;
}	t_player;

char		*ft_substr(char *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			get_player_pos(t_list *node, int choice);
void		flood_fill(t_list **lst, int x, int y);
void		*ft_calloc(size_t count, size_t size);
int			block_count(t_list *node, char block);
t_list		*new_map_line(char *line, int index);
char    	*get_line(t_list *node, int index);
int			get_next_line(int fd, char **res);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strjoin(char *s1, char *s2);
int			has_invalid_char(t_list *node);
int			starts_ends_1(t_list *node);
char		*ft_strchr(char *s, int c);
int			is_valid_map(t_list **ptr);
t_player	*spawn_player(t_list *map);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
int			flood_check(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstcopy(t_list *lst);
t_list		*getmap(char *map_path);
int			ft_lstsize(t_list *lst);
int			is_closed(t_list *ptr);
int			all_ones(char *string);
char		*ft_strdup(char *s1);
int			ft_strlen(char *s);



# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif