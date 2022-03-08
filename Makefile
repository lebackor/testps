

SRCS	=	check_errors.c\
			liste_chaine.c\
			movements.c\
			push_swap.c\
			algo.c\
			sort.c\
      		algo5.c\
			utils.c\

OBJS = ${SRCS:.c=.o}

CC	=	gcc

CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L libft -lft

NAME = push_swap

LIBFT = libft/libft.a

CLEAN_FT	=	make fclean -C libft

all : ${NAME}

${NAME} :	${OBJS} $(LIBFT)
	$(MAKE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}


$(LIBFT)	:
	make -C libft


clean :
		rm -f ${OBJS} ${LIBFT} 
		${CLEAN_FT}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
