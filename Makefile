SRC = src/main.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/parse.c \
	src/list.c \
	src/draw.c \

LIBFT_PATH = ./Libft/

CFLAGS = -MMD -Wall -Wextra -Werror -g
CC = gcc

NAME = fdf

DEP = $(SRC:.c=.d)

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/ \
		-I ./Libft/

Libft = Libft/libft.a

MLX = mlx/libmlx_Linux.a -lXext -lX11 

all: $(NAME)

.c.o:
	$(CC)  $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	@make -C Libft
	@$(CC) $(OBJ) $(MLX) $(Libft) -o $(NAME) $(INCLUDE)

clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean


-include $(DEP)

.SILENT:all

re: fclean all