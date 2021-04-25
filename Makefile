# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 17:09:11 by ldermign          #+#    #+#              #
#    Updated: 2021/04/25 17:53:56 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

SRCS	=	./main.c \
			./parsing/get_mapcub_infos.c ./parsing/get_map.c \
			./parsing/check_reso_floor_sky.c ./parsing/first_step_parsing.c \
			./parsing/check_arg.c \
			./utils/utils_check_get_player.c ./utils/utils_parsing_1.c \
			./utils/utils_parsing_2.c ./utils/utils_parsing_map.c \
			./others/clean_exit.c \
			./others/print_utils.c

INCS	=	-I ./includes/ -I ./libft/includes/ -I ./mlx/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

MLX		=	libmlx.dylib

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

RM		=	rm -rf

all:		${NAME}

.c.o:
			${MAKE} -C MLX
			cp mlx/${MLX} .
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} -I ${MLX} -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@ ./libft/libft.a

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
