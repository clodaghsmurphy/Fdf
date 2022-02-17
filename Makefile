SRC = src/main.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/parse.c \
	src/list.c \
	src/draw.c \
	src/matrix.c \

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

MATH = -lm

nb:=1

all: $(NAME)

.c.o:
	@echo -n "\033[32m"
	@$(CC)  $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
	@echo -n "\rFDF Objects compiled : " ${nb} 
	$(eval nb=$(shell echo $$(($(nb)+1))))


$(NAME): $(OBJ)
	@echo -n "\n"
	@make -C Libft
	@$(CC) $(OBJ) $(MLX)  $(Libft) -o $(NAME) $(MATH) $(INCLUDE)
	@echo "\nFdF pret!"

clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean


-include $(DEP)

.SILENT: $(NAME)

.PHONY: all re fclean clean

.SECONDARY: $(OBJ)

re: fclean all