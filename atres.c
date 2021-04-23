/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atres.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:33:26 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 08:13:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_hook(int keycode, void *param);
int		mouse_hook(int keycode, t_mlx *temp);
int		ft_close(int keycode, t_mlx *temp);


void	ft_init_img(t_data *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_circle_pixel(t_data img, int x, int y, int place)
{
	// int x = -400, y = -400, place = 200;
	while (x < 400)
	{
		y = -400;
		while (y < 400)
		{
			if (((x - place) * (x - place) + (y - place) * (y - place)) < 400)
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

int		mouse_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
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

int		ft_pressing(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	if (keycode != 53)
		printf("You are pressing the button [%d].\nEvents = 2, mask = 1L<<1\n", keycode);
	return (0);
}

int		ft_mouse_in_win(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	printf("The cursor is in the window.\nEvents = 4, mask = 1L<<4\n");
	return (0);
}

int		render_next_frame(int keycode, t_mlx a, t_data img)
{
	(void)a;
	(void)keycode;
	int x = -400, y = -400, place = 200;
	// if (keycode == 13)
		ft_circle_pixel(img, x, y, place);
		
	// mlx_put_image_to_window(a.mlx, a.win, img.img, 0, 0);
	return (0);
}

char	*circle(char *src)
{
	int i = -10, j = -10, x = 10;
	char *circle;

	circle = "";
	while (i < x)
	{
		while (j < x)
		{
			if ((i * i + j * j) < x * x)
				circle = ft_strjoin(circle, src);
			else
				circle = ft_strjoin(circle, " ");
			j++;
		}
		circle = ft_strjoin(circle, "\n");
		i++;
		j = -10;
	}
	return (circle);
}