# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2021/03/29 11:32:41 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d.a

INCS	=	cub3d.h

SRCS	=	./*.c ./libft/get_next_line.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

MLX		=	libmlx.dylib

LIBC	=	ar rc

LIBR	=	ranlib

RM		=	rm -rf

#.c.o:
#			${MAKE} -C libft
#			${MAKE} -C MLX
#			cp mlx/${MLX} .
#			${CC} ${CFLAGS} -Imlx -c $< -o $@

#${NAME}:	${OBJS} ./cub3d.h
#			${CC} ${CFLAGS} -Lmlx -lmlx -Ilibft -framework OpenGL -framework AppKit ${OBJS} -I ${INCS} -o ${NAME}
#			${LIBC} ${NAME} ${OBJS}
#			${LIBR}	${NAME}
.c.o:
			$(MAKE) -C libft
			$(MAKE) -C mlx
			cp mlx/$(MLX) .
			$(CC) ${CFLAGS} -c $< -o $@ -Imlx

${NAME}:	${OBJS}
			$(CC) ${CFLAGS} -Imlx -Ilibft -Llibft -lft -Lmlx -lmlx -lm -framework OpenGL -framework AppKit $(OBJS) -I $(INCS) -o $(NAME)

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