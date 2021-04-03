/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/03 17:57:18 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int keycode, t_mlx *temp);
int		ft_close(int keycode, t_mlx *temp);

void	ft_init_img(t_data *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
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

int		key_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	printf("key is [%d].\n", keycode);
	return (1);
}

int		mouse_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	printf("key is [%d].\n", keycode);
	return (1);
}

void		ft_close(int touche)
{
	printf("Goodbye !\n");
	exit(0);
}

int		render_next_frame(t_data img, void *myStruct)
{
	(void)myStruct;
	(void)img;
	// printf("test\n");
	return (1);
}

void	ft_events_loop(t_mlx a, t_data img)
{
	(void)img;
	if (keycode == 53)
		mlx_hook(a.win, 2, 1L<<0, ft_close, &a);

	
	// mlx_hook(a.win, 2, 1L<<5, ft_close, &a);
	// mlx_hook(a.win, 2, 1L<<0, ft_close, &a);
	// mlx_hook(a.win, 2, 1L<<0, ft_close, &a);
	// mlx_hook(a.win, 2, 1L<<0, ft_close, &a);
	// mlx_hook(a.win, 2, 1L<<0, ft_close, &a);
}

void	create_image(t_mlx a, t_data img)
{
	mlx_key_hook(a.win, key_hook, &a);
	mlx_mouse_hook(a.win, mouse_hook, &a);
	img.img = mlx_new_image(a.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_circle(img);
	mlx_put_image_to_window(a.mlx, a.win, img.img, 0, 0);
	ft_events_loop(a, img);
}

int		main()
{
	void *myStruct = NULL;
	t_data img;
	t_mlx a;

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 800, 800, "Cub3D");
	ft_init_img(&img);
	create_image(a, img);
	mlx_loop_hook(a.mlx, render_next_frame, myStruct);
	mlx_loop(a.mlx);
}
