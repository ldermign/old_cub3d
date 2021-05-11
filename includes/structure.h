/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:19:05 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/11 14:01:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    char        **map;
	int         player;
    double		plrX;
    double		plrY;
}				t_arg;

typedef struct  s_data {
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bpp;
    int         size_line;
    int         endian;
	int			width;
	int			height;
	int			sky;
	int			floor;

    int x;
    int y;

	double plrX; // vecteur positionnel du joueur // position
	double plrY;

    int         map_size;
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
**  FUNCTION POINTER
*/

typedef struct s_recup_data
{
	char	conv[3 + 1];
	void	(*f)(t_arg *data, char *str);
}	t_recup;

typedef struct s_texture
{
	char	conv[3 + 1];
	char	*(*f)(t_arg *data, char *str, char a, char b);
	char	**ptr;
}	t_text;
