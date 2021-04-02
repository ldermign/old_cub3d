/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/02 14:48:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_circle(t_data img)
{
	int x = -800, y = -800, place = 400;
	while (x < 800)
	{
		y = -800;
		while (y < 800)
		{
			if (((x - place) * (x - place) + (y - place) * (y - place)) < 800)
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			y += 2;
		}
		x += 2;
	}
}

void ft_rainbow(t_data img)
{
	int place = 0;
	
	while (place < 800)
	{
		my_mlx_pixel_put(&img, place, place, 0x00FF0000);
		place += 5;
	}
	while (place > 0)
	{
		my_mlx_pixel_put(&img, place, 800 - place, 0x000000FF);
		place -= 5;
	}
	ft_circle(img);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	printf("key is [%d] in int.\n", keycode);
	return (1);
}

int		mouse_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	printf("key is [%d] in int.\n", keycode);
	return (1);
}

int		ft_close(int keycode, t_mlx *temp)
{
	(void)temp;
	if (keycode == 53)
		mlx_destroy_window(temp->mlx, temp->win);
	return (1);
}

int		main(int ac, char **ag)
{
	// void *mlx;
	// void *win;
	t_data img;
	(void)ac;
	(void)ag;
	// t_mlx	hook;
	t_mlx	temp;

	temp.mlx = mlx_init();
	temp.win = mlx_new_window(temp.mlx, 800, 800, "Cub3D");
	mlx_key_hook(temp.win, key_hook, &temp);
	mlx_mouse_hook(temp.win, mouse_hook, &temp);
	img.img = mlx_new_image(temp.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_put_image_to_window(temp.mlx, temp.win, img.img, 0, 0);
	ft_rainbow(img);
	mlx_hook(temp.win, 2, 1L<<0, ft_close, &temp);
	mlx_loop(temp.mlx);
	return (0);
}

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