SRC = src/main.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/parse.c \
	src/list.c \

CFLAGS = -Wall -Wextra -Werror
CC = gcc

NAME = fdf

OBJ = $(SRC:.c=.o)

INCLUDE = include/fdf.h

Libft = Libft/libft.a

MLX = mlx/libmlx_Linux.a -lXext -lX11 

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(INCLUDE)
	make -C Libft
	$(CC) $(OBJ) $(MLX) $(Libft) $(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all