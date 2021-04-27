/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/27 13:32:01 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mouse_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	(void)keycode;
	printf("keycode is [%d].\n", keycode);
	return (0);
}

int		ft_close(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	if (keycode == 53)
	{
		printf("Goodbye !\n");
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
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