/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/29 13:32:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_arg *arg, t_spacemap *space)
{
	ft_memset(arg, 0, sizeof(t_arg));
	ft_memset(space, 0, sizeof(t_spacemap));
}

void	parsing(int ac, char **ag, t_arg *data)
{

	t_spacemap	space;

	ft_check_arg(ac, ag);
	init_struct(data, &space);
	gnl_mapcub(data, ag[1]);
	check_wrong_data_and_recup(data);
	recup_map(data);
	check_map(data, &space);
	printf_struct_arg(*data, space);
	// quit(&data, "All good.\n", 3, 0);
}

int		ft_close_escape(int keycode, t_arg *data)
{
	(void)data;
	if (keycode == 53)
	{
		printf("You pressed the escape button.\n");
		printf("Goodbye !\n");
		// quit(data, "All good.\n", 3, 0);
		exit(0);
	}
	return (0);
}

int		ft_close_cross(t_arg *data)
{
	(void)data;
	printf("You clicked on the cross.\n");
	printf("Goodbye !\n");
	// quit(data, "All good.\n", 3, 0);
	exit(0);
	return (0);
}

void	print_keycode(int keycode)
{
	printf("Keycode is = %d'\n", keycode);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

//	place = endroit ou il sera place
void ft_circle_pixel(t_mlx img, int x, int y, int place)
{
	x = -400, y = -400, place = 400;
	while (x < 800)
	{
		y = -400;
		while (y < 800)
		{
			if (((x - place) * (x - place) + (y - place) * (y - place)) < 800)
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			y += 2;
		}
		x += 2;
	}
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	(void)keycode;
	// printf("keycode is [%d].\n", keycode);
	return (0);
}

int		key_hook_2(int keycode, t_mlx *img)
{
	if (keycode == 13)
		img->x++;
	if (keycode == 1)
		img->y++;
	if (keycode == 0)
		img->x--;
	if (keycode == 2)
		img->y--;
	return (0);
}

int	test(t_mlx *img)
{
	my_mlx_pixel_put(img->mlx, img->x, img->y, 0x0000FF00);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int		main(int ac, char **ag)
{
	t_arg data;
	t_mlx img;
	
	ft_memset(&img, 0, sizeof(t_mlx));
	parsing(ac, ag, &data);
	
	img.mlx = mlx_init();

	/*
	**
	*/
	img.win = mlx_new_window(img.mlx, data.res_x, data.res_y, "Cub3D");
	
	/*
	**	pour quitter proprement
	*/
	mlx_hook(img.win, 2, 1L<<0, ft_close_escape, &img);
	mlx_hook(img.win, 17, 1L<<0, ft_close_cross, &img);

	/*
	**
	*/
	mlx_key_hook(img.win, key_hook, print_keycode);
	mlx_mouse_hook(img.win, mouse_hook, &img);

	/*
	**	creation image avec texture brick wall dedans (utilisation xpm)
	*/
	img.img = mlx_xpm_file_to_image(img.mlx, data.east, &data.res_x, &data.res_y);
	
	/*
	**	creation image neutre, ou on peit ecrire dedans
	*/
	// img.img = mlx_new_image(img.mlx, data.res_x, data.res_y);

	/*
	**	retourne le debut de l'adresse de l'image creee, peut etre utilisee ensuite.
	**	bpp = nombre de bits utiles pour representer une couleur en pixel,
	**	represente le premier pixel de la premiere ligne de l'image (aussi
	**	appele la profondeur de l'image)
	**	size_line = nombre de bits utilises pour stocker une ligne de l'image
	**	utile pour aller d'une ligne a l'autre dans l'image
	**	endian = precise si la couleur du pixel de l'image doit etre stockee
	**	dans un petit (== 0) ou un grand (== 1) endian
	*/	
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);

	// mlx_hook(img.win, 3, 1L<<0, key_hook_2, &img);
	// mlx_key_hook(img.win, key_hook, &img);
	// mlx_loop_hook(img.mlx, test, &img);

	// ft_circle_pixel(img, 0, 0, 400);

	/*
	**	on place l'image sur la fenetre
	*/
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	
	// mlx_loop_hook(a.mlx, render_next_frame, myStruct);

	/*
	**	faire tourner la fenetre en continuite
	*/
	mlx_loop(img.mlx);

	// return (0);
}

