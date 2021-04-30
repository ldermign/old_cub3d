/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/30 13:40:07 by ldermign         ###   ########.fr       */
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

int	test(t_mlx *img)
{
	printf("img->x = %d, img->y = %d.\n", img->x, img->y);
	my_mlx_pixel_put(img, img->x, img->y, 0x0000FF00);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int		move_pixel(int keycode, t_mlx *img)
{
	if (keycode == 2) //bon, d, droite
		img->x++;
	if (keycode == 1) // bon, w, haut
		img->y++;
	if (keycode == 0) // bon, a, gauche
		img->x--;
	if (keycode == 13) // bon, s, bas
		img->y--;
	my_mlx_pixel_put(img, img->x, img->y, 0x0000FF00);
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
	img.win = mlx_new_window(img.mlx, data.res_x, data.res_y, "Cub3D");

	// mlx_key_hook(img.win, key_hook, print_keycode);
	// mlx_mouse_hook(img.win, mouse_hook, &img);
	
	// img.img = mlx_xpm_file_to_image(img.mlx, data.east, &data.res_x, &data.res_y);
	img.img = mlx_new_image(img.mlx, data.res_x, data.res_y);

	// mlx_hook(img.win, 2, 1L<<0, move_pixel, &img);
	mlx_hook(img.win, 2, 1L<<0, ft_close_escape, &img);
	mlx_hook(img.win, 17, 1L<<0, ft_close_cross, &img);

	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	
	// mlx_loop_hook(img.win, test, &img);
	// mlx_loop(img.mlx);

	// mlx_hook(img.win, 4, 1L<<0, move_pixel, &img);
	mlx_key_hook(img.win, move_pixel, &img);

	// my_mlx_pixel_put(&img, img.x, img.y, 0x0000FF00);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	// mlx_loop_hook(a.mlx, render_next_frame, myStruct);

	mlx_loop(img.mlx);

	// return (0);
}

