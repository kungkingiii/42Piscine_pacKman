CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext
INCLUDE = -I./includes
LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a
RM = rm -rf
NAME = so_long

SRCS = map.c key.c error.c img.c player.c window.c main.c check_path.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	make -C libft/
	make -C mlx/
	make -C ft_printf/
	$(CC) $(CFLAGS) $(OBJS) ft_printf/libftprintf.a mlx/libmlx.a libft/libft.a $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make clean -C libft/
	make clean -C mlx/
	make clean -C ft_printf/
	$(RM) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
