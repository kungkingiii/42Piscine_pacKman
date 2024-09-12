# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 22:24:55 by packmanich        #+#    #+#              #
#    Updated: 2024/09/12 23:19:01 by packmanich       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c util.c init.c threads.c routine.c

MANPATH = $(addprefix ./, $(SRC))

FLAGS = -O3 -pthread

HEADER = ./philosopher.h

# SANITIZER = -fsanitize=thread

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: FLAGS += -g
debug: re

delay:
	python3 delay_o_meter.py
