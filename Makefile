SRC = main.c 

CFLAGS = -Wall -Wextra -Werror
CC = gcc

NAME = fdf

OBJ = $(SRC: .c=.o)

MLX = mlx/libmlx_Linux.a -lXext -lX11 

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all