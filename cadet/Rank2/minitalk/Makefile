NAME = minitalk
NAME_C = client
NAME_S = server
SRC_C = client.c
SRC_S = server.c
OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

LIB = libft/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

main: libft $(NAME)

$(NAME): $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_C) -o $@ $(LIB)

$(NAME_S): $(OBJ_S) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_S) -o $@ $(LIB)

libft:
	@ make -C libft/

clean:
	$(REMOVE) $(OBJ_C) $(OBJ_S)
	make -C libft/ clean

fclean: clean
	$(REMOVE) $(NAME_C) $(NAME_S)
	make -C libft/ fclean

re: fclean main

.PHONY: libft main clean fclean re re_bonus
