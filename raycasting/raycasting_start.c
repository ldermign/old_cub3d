/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/17 14:55:49 by ldermign         ###   ########.fr       */
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
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	get_orientation_player(clcls, data);
	while (i < img->width)
	{
		init_calculs(img, clcls, i);
		step_calculs(clcls);
		which_square_with_wall_DDA(clcls, data);
		distance_camera_calculs(img, clcls);
		draw_line_wall(img, i, clcls->drawStart, clcls->drawEnd, clcls->side);
		i++;
	}
	// mlx_hook(img->win, 2, 1L<<0, &key_press, (void *)0);
	mlx_hook(img->win, 3, 1L<<1, &key_release, (void *)0);
	// mlx_key_hook(img->win, &key_release, (void *)0);d
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);

	// mlx_key_hook(img.win, &move_player, (void*)0);
	// mlx_hook(img.win, 2, 1L<<0, &move_player, (void*)0);
	
	//timing for input and FPS counter
	// img.oldTime = img.time;
	// img.time = getTicks(); // refaire
	// double frameTime = (img.time - img.oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	// print(1.0 / frameTime); //FPS counter
	// redraw(); // pas forcement ?
	// cls(); //pas forcement ??

	// speed modifiers
	// double moveSpeed = 5.0; //the constant value is in squares/second
	// double rotSpeed = 3.0; //the constant value is in radians/second


	// readKeys(); // refaire
	// move forward if no wall in front of you
	// if (key_down(13))
	// {
	// 	if(data.map[(int)img.plrX + (int)img.dirX * (int)moveSpeed][(int)img.plrY] == 0) img.plrX += img.dirX * moveSpeed;
	// 	if(data.map[(int)img.plrX][(int)img.plrY + (int)img.dirY * (int)moveSpeed] == 0) img.plrY += img.dirY * moveSpeed;
	// }
	// //move backwards if no wall behind you
	// if (key_down(1))
	// {
	// 	if(data.map[(int)(img.plrX - img.dirX * moveSpeed)][(int)img.plrY] == 0) img.plrX -= img.dirX * moveSpeed;
	// 	if(data.map[(int)img.plrX][(int)(img.plrY - img.dirY * moveSpeed)] == 0) img.plrY -= img.dirY * moveSpeed;
	// }
	// //rotate to the right
	// if (key_down(2))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = img.dirX;
	// 	img.dirX = img.dirX * cos(-rotSpeed) - img.dirY * sin(-rotSpeed);
	// 	img.dirY = oldDirX * sin(-rotSpeed) + img.dirY * cos(-rotSpeed);
	// 	double oldPlaneX = img.planeX;
	// 	img.planeX = img.planeX * cos(-rotSpeed) - img.planeY * sin(-rotSpeed);
	// 	img.planeY = oldPlaneX * sin(-rotSpeed) + img.planeY * cos(-rotSpeed);
	// }
	// //rotate to the left
	// if (key_down(0))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = img.dirX;
	// 	img.dirX = img.dirX * cos(rotSpeed) - img.dirY * sin(rotSpeed);
	// 	img.dirY = oldDirX * sin(rotSpeed) + img.dirY * cos(rotSpeed);
	// 	double oldPlaneX = img.planeX;
	// 	img.planeX = img.planeX * cos(rotSpeed) - img.planeY * sin(rotSpeed);
	// 	img.planeY = oldPlaneX * sin(rotSpeed) + img.planeY * cos(rotSpeed);
	// }
}
