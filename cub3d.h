/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:40:28 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/06 16:35:21 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bpp;
    int         line_len;
    int         endian;
	int			width;
	int			height;
}               t_data;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
}               t_mlx;

typedef struct  s_input {
    int sp;
    int ret;
    int w;
    int a;
    int s;
    int d;
    int f;
    int l;
    int m;
    int arr_u;
    int arr_d;
    int arr_l;
    int arr_r;
    int mouse_l;
    int mouse_r;
    int touche;
}               t_ipt;

typedef struct  s_xy {
    int x;
    int y;
}               t_xy;

# include <libc.h>

#endif


/*
RGB colors can be initialized as above, a few examples would be:
Red: 0x00FF0000;
Green: 0x0000FF00;
Blue: 0x000000FF;
Keycode
w = 0x0D
space = 49
arrow up = 126
arrow down = 125
arrow left = 123
arrow right = 124
s = 1
a = 0
d = 2
f = 3
m = 46
l = 37
enter = 36
delete = 51
left mouse = 1
right mouse = 2
molette haut = 5
molette bas = 4
esc = 53
*/