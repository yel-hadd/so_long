/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:22:00 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/18 14:57:19 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct map
{
	char			*line;
	int				index;
	int				coins;
	int				exit[2];
	struct map		*next;
}	t_map;

typedef struct player
{
	int				x;
	int				y;
	int				collected;
	struct player	*next;
}	t_player;

typedef struct building_blocks
{
	void					*pr;
	void					*pl;
	void					*pu;
	void					*pd;
	void					*c;
	void					*e;
	void					*o;
	void					*w;	
	struct building_blocks	*next;
}	t_blocks;

typedef struct mlx_pointers
{
	void				*ptr;
	void				*win;
	t_map				*map;
	t_player			*p;
	t_blocks			*b;
	int					exit[2];
	int					move;
	struct mlx_pointers	*next;
}	t_mlx;

void		draw_map(void *ml, void *win, t_map *map, t_blocks *blocks);
char		*ft_substr(char *s, unsigned int start, size_t len);
t_mlx		*load_mlx(t_map *map, t_player *p, char *title);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		ft_lstadd_back(t_map **lst, t_map *new);
int			get_player_pos(t_map *node, int choice);
int			block_is_coin(t_map *map, int x, int y);
int			block_is_wall(t_map *map, int x, int y);
int			block_is_exit(t_map *map, int x, int y);
void		flood_fill(t_map **lst, int x, int y);
void		*ft_calloc(size_t count, size_t size);
t_map		*new_map_line(char *line, int index);
int			block_count(t_map *node, char block);
char		*get_line(t_map *node, int index);
int			get_next_line(int fd, char **res);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strjoin(char *s1, char *s2);
t_blocks	*load_blocks(void *mlx_ptr);
int			has_invalid_char(t_map *node);
t_player	*spawn_player(t_map *map);
void		ft_putnbr_fd(int n, int fd);
int			starts_ends_1(t_map *node);
char		*ft_strchr(char *s, int c);
int			is_valid_map(t_map **ptr);
void		ft_lstdelone(t_map *lst);
void		ft_lstclear(t_map **lst);
int			flood_check(t_map **lst);
t_map		*ft_lstlast(t_map *lst);
t_map		*ft_lstcopy(t_map *lst);
t_map		*getmap(char *map_path);
void		move_right(t_mlx *game);
int			ft_lstsize(t_map *lst);
int			all_ones(char *string);
void		move_down(t_mlx *game);
void		move_left(t_mlx *game);
int			is_closed(t_map *ptr);
int			same_len(t_map *node);
void		free_mlx(t_mlx **ptr);
char		*ft_strdup(char *s1);
void		move_up(t_mlx *game);
int			ft_strlen(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

#endif