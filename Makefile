NAME = libftprintf.a

CC = gcc

FLAGS    = -Wall -Wextra -Werror

DEL = /bin/rm -f

SRCS =     ft_printf.c\
		ft_printf_percent.c\
		ft_printf_percent2.c\
		ft_printf_utils.c\

SRCS_O    = ${SRCS:.c=.o}

all: $(NAME)

LIBC    = ar -rcs

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
			${LIBC} $(NAME) $(SRCS_O)

fclean: clean
		$(DEL) $(NAME)

clean:
		$(DEL) $(SRCS_O)

re: fclean all
