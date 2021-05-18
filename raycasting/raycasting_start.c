/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/18 13:52:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	draw_line_wall(t_mlx *img, int x, int start, int end, int side)
{
	int color;

	color = create_trgb(1, 255, 255, 255);
	if (side == 1)
		color = create_trgb(1, 200, 50, 100);;
	while (start < end)
	{
		my_mlx_pixel_put(img, x, start, color);
		start++;
	}
}

void	get_orientation_player(t_calc *clcls, t_arg *data)
{
	if ((char)data->player == 'E')
	{
		clcls->dirY = 1;
		clcls->planeX = 0.66;
	}
	else if ((char)data->player == 'N')
	{
		clcls->dirX = -1;
		clcls->planeY = 0.66;
	}
	else if ((char)data->player == 'W')
	{
		clcls->dirY = -1;
		clcls->planeX = -0.66;
	}
	else if ((char)data->player == 'S')
	{
		clcls->dirX = 1;
		clcls->planeY = -0.66;
	}
}

void	start_raycasting(t_mlx *img, t_calc *clcls, t_arg *data)
{
	int i;

	i = 0;
	fill_sky_and_floor(img);
	// mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	get_orientation_player(clcls, data);
	// printf("test1\n");
	while (i < img->width)
	{
		// printf("test\n");
		init_calculs(img, clcls, i);
		step_calculs(clcls);
		which_square_with_wall_DDA(clcls, data);
		distance_camera_calculs(img, clcls);
		draw_line_wall(img, i, clcls->drawStart, clcls->drawEnd, clcls->side);
		mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
		i++;
	}
	// printf("nique\n");
	// mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);

	// mlx_hook(img->win, 2, 1L<<0, &key_press, (void *)0);
	// mlx_hook(img->win, 2, 1L<<0, &key_release, (void *)0);
	// mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
	// mlx_key_hook(img->win, &key_release, (void *)0);d
	// mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
