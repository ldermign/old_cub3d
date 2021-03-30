# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2021/03/30 13:54:20 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

INCS	=	./incs

SRCS	=	cub3d.c

LIBFT	=	./libft

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

MLX		=	libmlx.dylib

RM		=	rm -rf

.c.o:
			${MAKE} -C MLX
			cp mlx/${MLX} .
			${CC} ${CFLAGS} -Imlx -c $< -o $@ -I ${INCS}

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} -I ${INCS} -o ${NAME} ${OBJS} -Lmlx -lft -lmlx -I ${LIBFT} -L ${LIBFT} -framework OpenGL -framework AppKit
#			${CC} ${CFLAGS} -Imlx -lft -lm -framework OpenGL -framework AppKit ${OBJS} -I ${INCS} -o ${NAME}

all:		${NAME}

clean:
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${MLX}
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
