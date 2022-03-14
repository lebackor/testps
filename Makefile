# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebackor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 14:39:49 by lebackor          #+#    #+#              #
#    Updated: 2022/03/14 14:39:51 by lebackor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
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
