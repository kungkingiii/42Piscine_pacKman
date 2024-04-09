SRCS			= ft_printf.c ft_printhex.c ft_printletter.c ft_printnbr.c ft_printptr.c 
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C ./libft
				cp libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJS)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS) 

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re