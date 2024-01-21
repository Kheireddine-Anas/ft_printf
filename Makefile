NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -rf

SRCS	= ft_printcs.c ft_printdiu.c ft_printf.c ft_printxxp.c

OBJS	= ${SRCS:.c=.o}

${NAME}: ${OBJS} ft_printf.h
		${AR} rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
