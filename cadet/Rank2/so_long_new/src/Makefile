CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
INC=%%%%
INCLIB=$(INC)/../lib
NAME= so_long

LIB = ../lib
LIBFT = $(LIB)/libftprintf.a

SRC_DIR = src
SRC_FILES = main.c window.c map.c util.c mapcheck.c pathcheck.c image.c draw_map.c handle_move.c
SRC_PATHS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ_DIR = ../obj
OBJ = $(SRC_PATHS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LFLAGS = -L ../$(MLX_PATH) -lmlx -Ilmlx -lXext -lX11
MLX_PATH = minilibx-linux/

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIB)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)


clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIB)
	$(MAKE) clean -C $(LIB)/libft

fclean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME) $(OBJ)
	$(RM) $(LIBFT)
	$(RM) $(LIB)/libft/libft.a
	$(MAKE) fclean -C $(LIB)
	$(MAKE) clean -C $(LIB)/libft

re: clean all
