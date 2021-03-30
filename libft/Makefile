# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 19:45:34 by ldermign          #+#    #+#              #
#    Updated: 2021/03/30 13:06:36 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

INCS	=	./incs/

SRCS	=	ft_strrchr.c ft_isalnum.c ft_memchr.c ft_strlcat.c ft_tolower.c \
			ft_isalpha.c ft_isdigit.c ft_memmove.c ft_memccpy.c ft_strchr.c \
			ft_strlcpy.c ft_memcmp.c ft_toupper.c ft_memcpy.c ft_isascii.c \
			ft_strlen.c ft_isprint.c ft_memset.c ft_strnstr.c ft_bzero.c \
			ft_strncmp.c ft_atoi.c ft_calloc.c ft_itoa.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strdup.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
			get_next_line_utils.c get_next_line.c \
			check.c conversion_p_d_i_u_x.c conversion_s_c_per.c ft_printf.c \
			start_fusion.c fusion_strflag_conv_cps.c utils_size.c \
			fusion_strflag_conv_dius.c fusion_strflag_conv_s_utils.c \
			init_flags.c join_width_preci.c utils.c utils_itoa.c 
			

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	ar rc

LIBR	=	ranlib

RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS} ${INCS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR}	${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
