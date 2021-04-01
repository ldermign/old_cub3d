/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/01 14:14:28 by ldermign         ###   ########.fr       */
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
	while (place > 0)
	{
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
		place -= 100;
		x = -800;
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

int		main()
{
	void *mlx;
	void *win;
	t_data img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "Cub3D");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_rainbow(img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// RGB colors can be initialized as above, a few examples would be:

// Red: 0x00FF0000;
// Green: 0x0000FF00;
// Blue: 0x000000FF;