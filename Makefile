NAME = so_long
HEADER = solong.h
SRC := main.c \
	utils/has_invalid_char.c \
	utils/get_player_pos.c \
	utils/ft_lstadd_back.c \
	utils/block_is_coin.c \
	utils/block_is_wall.c \
	utils/block_is_exit.c \
	utils/get_next_line.c \
	utils/starts_ends_1.c \
	utils/ft_lstdelone.c \
	utils/is_valid_map.c \
	utils/new_map_line.c \
	utils/spawn_player.c \
	utils/load_blocks.c \
	utils/is_new_line.c \
	utils/block_count.c \
	utils/flood_check.c \
	utils/ft_lstclear.c \
	utils/move_right.c \
	utils/ft_strtrim.c \
	utils/ft_lstlast.c \
	utils/ft_lstsize.c \
	utils/flood_fill.c \
	utils/ft_strjoin.c \
	utils/ft_lstcopy.c \
	utils/move_left.c \
	utils/move_down.c \
	utils/ft_substr.c \
	utils/ft_memcpy.c \
	utils/ft_calloc.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strlen.c \
	utils/is_closed.c \
	utils/draw_map.c \
	utils/free_mlx.c \
	utils/load_mlx.c \
	utils/all_ones.c \
	utils/get_line.c \
	utils/same_len.c \
	utils/move_up.c \
	utils/isalnum.c \
	utils/getmap.c

OBJ        := $(SRC:.c=.o)

%.o : %.c ${HEADER}
	@cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	@cc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re