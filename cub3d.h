/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:40:28 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 17:01:36 by ldermign         ###   ########.fr       */
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

typedef	struct	s_argmts {
	int			tmp;
    int         last;
    int         len_fd;
	int			res_x;
	int			res_y;
	int 		flr_r;
	int		 	flr_g;
	int 		flr_b;
	int 		ciel_r;
	int			ciel_g;
	int 		ciel_b;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	char		**fd;
    char        **map_final;
}				t_arg;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bpp;
    int         line_len;
    int         endian;
	int			width;
	int			height;
}               t_data;

typedef struct  s_map
{
    int         player;
    int         ply_x;
    int         ply_y;
    int         ply_N;
    int         ply_S;
    int         ply_W;
    int         ply_E;
}               t_spacemap;


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

/*
**	CHECK
*/

int		ft__save(char *arg);
int		ft_check_name_map(char *arg);
void	ft_check_arg(int ac, char **ag);
void	check_map(t_arg *data, t_spacemap *space);
void	check_wrong_data_and_recup(t_arg *data);


/*
**	SAVE INFOS
*/

void	gnl_mapcub(t_arg *data, char *arg);
void	recup_data(t_arg *data, char *str);
void	recup_map(t_arg *data);

/*
**	UTILS
*/

int		space_or_element(int c);
int		ft_int_strstr(char *str, char *needle);
int		ft_int_strchr(const char *str, int c);
int		space_or_comma(int c);
int		element(int c);
int		full_of(char *str, char c);
int		size_tab_char(char **tab);
int		pos_last(char *str, char c);
int		ft_strchr_tab_wrong_cara(char **tab);
int		return_player(char **map);
int		how_many_player(t_arg *data, char **map);
void	get_position_player(t_arg *data, t_spacemap *space);

/*
**  UTILS MAP
*/

int		ft_is_player(int c);
int		ft_is_map(char c);
void	map_valid(char **tab);
int		cara_in_map(int c);
int		ft_is_noting(char *str);
int		ft_is_either(char *str);
int		get_position(char **tab, int c);
int		next_cara(const char *str, int c);
int		which_is_larger(char **tab);
char	*ft_strdup_map_line(char *s1, int length);


/*
**  CLEAN EXIT
*/

void	quit(t_arg *data, char *str_err, int i, int place);
















/*
**  OTHERS
*/



















/*
**  A TEJ
*/


#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // GRIS
#define CLR_COLOR "\x1b[0m" // CLEAR COLOR
void	printf_struct_arg(t_arg data, t_spacemap space);

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


//              1111111111111111111111111
//              1000000001100000000000001
//              1011000001110000000000001
//              1001000000000000000000001
//      111111111011000001110000000000001
//      100000000110000011101111111111111
//      1110111111111011100000010001
//      11110111111111011101010010001
//   111110000001101010111000000100001111111
//  100000020000000000011000000100000011011
//  1000000000000000000110101001N00000011
//  111000001110001011111011110000000111
//    111111011111110101 1011110100000001
//      1111111 1111111 11111111111111111