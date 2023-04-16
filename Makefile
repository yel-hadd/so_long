NAME = solong
HEADER = solong.h
SRC := main.c \
	utils/load_blocks.c \
	utils/all_ones.c \
	utils/ft_lstdelone.c \
	utils/ft_strtrim.c \
	utils/is_new_line.c \
	utils/block_count.c \
	utils/ft_lstlast.c \
	utils/ft_substr.c \
	utils/is_valid_map.c \
	utils/flood_check.c \
	utils/ft_lstsize.c \
	utils/get_line.c \
	utils/isalnum.c \
	utils/flood_fill.c \
	utils/ft_memcpy.c \
	utils/get_next_line.c \
	utils/new_map_line.c \
	utils/ft_calloc.c \
	utils/ft_strchr.c \
	utils/get_player_pos.c \
	utils/same_len.c \
	utils/ft_lstadd_back.c \
	utils/ft_strdup.c \
	utils/getmap.c \
	utils/spawn_player.c \
	utils/ft_lstclear.c \
	utils/ft_strjoin.c \
	utils/has_invalid_char.c \
	utils/starts_ends_1.c \
	utils/ft_lstcopy.c \
	utils/ft_strlen.c \
	utils/is_closed.c \

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