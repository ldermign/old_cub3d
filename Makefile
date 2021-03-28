# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2021/03/28 17:21:48 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d.a

SRCS	=	./*.c ./libft/* ./mlx/*


OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	ar rc

LIBR	=	ranlib

RM		=	rm -f

%.o: %.c
			${CC} ${CFLAGS} -Imlx -c $< -o $@ ${<:.c=.o}

$(NAME):	${OBJS} ./cub3d.h
			${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
			${LIBC} ${NAME} ${OBJS}
			${LIBR}	${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re