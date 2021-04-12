# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 19:45:34 by ldermign          #+#    #+#              #
#    Updated: 2021/04/09 17:37:44 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	./srcs/ft_strrchr.c \
			./srcs/ft_isalnum.c \
			./srcs/ft_memchr.c \
			./srcs/ft_strlcat.c \
			./srcs/ft_tolower.c \
			./srcs/ft_isalpha.c \
			./srcs/ft_isdigit.c \
			./srcs/ft_memmove.c \
			./srcs/ft_memccpy.c \
			./srcs/ft_strchr.c \
			./srcs/ft_strlcpy.c \
			./srcs/ft_memcmp.c \
			./srcs/ft_toupper.c \
			./srcs/ft_memcpy.c \
			./srcs/ft_isascii.c \
			./srcs/ft_strlen.c \
			./srcs/ft_isprint.c \
			./srcs/ft_memset.c \
			./srcs/ft_strnstr.c \
			./srcs/ft_bzero.c \
			./srcs/ft_strncmp.c \
			./srcs/ft_atoi.c \
			./srcs/ft_calloc.c \
			./srcs/ft_itoa.c \
			./srcs/ft_putchar_fd.c \
			./srcs/ft_putendl_fd.c \
			./srcs/ft_putnbr_fd.c \
			./srcs/ft_putstr_fd.c \
			./srcs/ft_split.c \
			./srcs/ft_strdup.c \
			./srcs/ft_strjoin.c \
			./srcs/ft_strmapi.c \
			./srcs/ft_strtrim.c \
			./srcs/ft_substr.c \
			./srcs/ft_strcmp.c \
			./srcs/ft_putchar.c \
			./srcs/ft_strncpy.c \
			./srcs/ft_swap.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strcpy.c \
			./srcs/ft_strcat.c \
			./srcs/ft_strncat.c \
			./srcs/get_next_line_utils.c \
			./srcs/get_next_line.c \
			./srcs/check.c \
			./srcs/conversion_p_d_i_u_x.c \
			./srcs/conversion_s_c_per.c \
			./srcs/ft_printf.c \
			./srcs/start_fusion.c \
			./srcs/fusion_strflag_conv_cps.c \
			./srcs/utils_size.c \
			./srcs/fusion_strflag_conv_dius.c \
			./srcs/fusion_strflag_conv_s_utils.c \
			./srcs/init_flags.c \
			./srcs/join_width_preci.c \
			./srcs/utils.c \
			./srcs/utils_itoa.c

IDIR	=	./includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I ${IDIR}

LIBC	=	ar rc

LIBR	=	ranlib

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR}	${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
