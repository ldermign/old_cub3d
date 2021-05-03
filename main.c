/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/03 15:32:14 by ldermign         ###   ########.fr       */
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
	// printf_struct_arg(*data, space);
	// quit(&data, "All good.\n", 3, 0);
}

int		ft_close_escape(int keycode, t_mlx *img)
{
	(void)img;
	if (keycode == 53)
	{
		printf("You pressed the escape button.\n");
		printf("Goodbye !\n");
		// quit(data, "All good.\n", 3, 0);
		exit(0);
	}
	return (0);
}

int		ft_close_cross(t_mlx *img)
{
	(void)img;
	printf("You clicked on the cross.\n");
	printf("Goodbye !\n");
	// quit(data, "All good.\n", 3, 0);
	exit(0);
	return (0);
}

int	print_keycode(int keycode, t_mlx *img)
{
	(void)img;
	printf("Keycode is = %d.\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int 	afficher_coor_souris(t_mlx *img)
{
	(void)img;
	// printf("x = %d, y = %d.\n", );
	return (0);
}

int 	souris_entree()
{
	printf("Congrats ! You entered in the window...\n");
	return (0);
}

int 	souris_sortie(t_mlx *img)
{
	(void)img;
	printf("You are leaving so soon...\n");
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

// int 	key_hook(int keycode, t_mlx *img)
// {
// 	printf("Keycode is = %d.\n", keycode);
// 	if (keycode == 53)
// 		mlx_hook(img->win, 2, 1L<<0, ft_close_escape, img);
// 	mlx_hook(img->win, 17, 1L<<0, ft_close_cross, img);
// 	mlx_hook(img->win, 3, 1L<<1, move_pixel, img);
// 	return (0);
// }

void	ft_fill_img(t_mlx *img, int color)
{
	int x;
	int y;
	int pixel;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			pixel = (y * img->size_line) + (x * 4);
			if (img->endian == 1)
			{
				img->addr[pixel + 0] = (color >> 24);
				img->addr[pixel + 1] = (color >> 16) & 0xFF;
				img->addr[pixel + 2] = (color >> 8) & 0xFF;
				img->addr[pixel + 3] = (color) & 0xFF;
			}
			else if (img->endian == 0)
			{
				img->addr[pixel + 0] = (color) & 0xFF;
				img->addr[pixel + 1] = (color >> 8) & 0xFF;
				img->addr[pixel + 2] = (color >> 16) & 0xFF;
				img->addr[pixel + 3] = (color >> 24);
			}
			++y;
		}
		++x;
	}
}

void	fill_sky_and_floor(t_mlx *img)
{
	int x;
	int y;
	int pixel;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height / 2)
		{
			pixel = (y * img->size_line) + (x * 4);
			if (img->endian == 1)
			{
				img->addr[pixel + 0] = (img->sky >> 24);
				img->addr[pixel + 1] = (img->sky >> 16) & 0xFF;
				img->addr[pixel + 2] = (img->sky >> 8) & 0xFF;
				img->addr[pixel + 3] = (img->sky) & 0xFF;
			}
			else if (img->endian == 0)
			{
				img->addr[pixel + 0] = (img->sky) & 0xFF;
				img->addr[pixel + 1] = (img->sky >> 8) & 0xFF;
				img->addr[pixel + 2] = (img->sky >> 16) & 0xFF;
				img->addr[pixel + 3] = (img->sky >> 24);
			}
			++y;
		}
		++x;
	}
	while (x < img->width)
	{
		y = 0;
		while (y < img->height / 2)
		{
			pixel = (y * img->size_line) + (x * 4);
			if (img->endian == 1)
			{
				img->addr[pixel + 0] = (img->floor >> 24);
				img->addr[pixel + 1] = (img->floor >> 16) & 0xFF;
				img->addr[pixel + 2] = (img->floor >> 8) & 0xFF;
				img->addr[pixel + 3] = (img->floor) & 0xFF;
			}
			else if (img->endian == 0)
			{
				img->addr[pixel + 0] = (img->floor) & 0xFF;
				img->addr[pixel + 1] = (img->floor >> 8) & 0xFF;
				img->addr[pixel + 2] = (img->floor >> 16) & 0xFF;
				img->addr[pixel + 3] = (img->floor >> 24);
			}
			++y;
		}
		++x;
	}
}

int		main(int ac, char **ag)
{
	t_arg data;
	t_mlx img;
	
	ft_memset(&img, 0, sizeof(t_mlx));
	parsing(ac, ag, &data);
	img.width = data.res_x;
	img.height = data.res_y;
	img.sky = create_trgb(get_t(1), data.ciel_r, data.ciel_g, data.ciel_b);
	img.floor = create_trgb(get_t(1), data.flr_r, data.flr_g, data.flr_b);

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);

	// ft_fill_img(&img, img.sky); // fonctionne ! pas toucher, s'inspirer
	fill_sky_and_floor(&img);

	// PAS TOUCHER
	// mlx_key_hook(img.win, print_keycode, &img);
	mlx_hook(img.win, 2, 1L<<0, ft_close_escape, &img);
	mlx_hook(img.win, 17, 1L<<0, ft_close_cross, &img);


	// TEST
	// mlx_mouse_hook(img.win, afficher_coor_souris, &img);
	// mlx_hook(img.win, 2, 1L<<0, move_pixel, &img); // fonctionne avec 2 et 1L<<0 mais pas escape
	// mlx_hook(img.win, 7, 1L<<4, souris_entree, (void *)0);
	// mlx_hook(img.win, 8, 1L<<5, souris_sortie, (void *)0);
	// mlx_hook(img.win, 6, 1L<<6, afficher_coor_souris, &img);
	// mlx_key_hook(img.win, move_pixel, &img);
	// mlx_loop_hook(a.mlx, render_next_frame, myStruct);

	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	mlx_loop(img.mlx);
	return (0);
}

