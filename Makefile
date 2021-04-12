# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2021/04/12 11:54:28 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

IDIR	=	./includes

SRCS	=	./main.c ./print_utils.c ./init_struct.c ./utils_cub3d.c \
			./get_mapcub_infos.c ./check_arg.c

LIBFT	=	./libft

OBJS	=	${SRCS:.c=.o}

CC		=	clang

MLX		=	libmlx.dylib

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -I ${IDIR} -I ${MLX}

RM		=	rm -rf

all:		${NAME}

.c.o:
			${MAKE} -C MLX
			cp mlx/${MLX} .
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${LIBFT} -L ${LIBFT} -Lmlx -lft -lmlx -I ${LIBFT} -L ${LIBFT} -framework OpenGL -framework AppKit

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
