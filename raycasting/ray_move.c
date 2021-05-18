/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:18:23 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/18 13:45:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keycode, t_mlx *img, t_calc *cls, t_arg *data)
{
	(void)img;
	// cls->dirX = -1, cls->dirY = 0, cls->planeX = 0, cls->planeY = 0.66;
	// cls->dirX = -1;
	// printf("test\n");
	double moveSpeed = 0.1; //the constant value is in squares/second
	double rotSpeed = 0.1; //the constant value is in radians/second

	if (keycode == 13)
	{
		if (data->map[(int)cls->plrX + (int)cls->dirX * (int)moveSpeed][(int)cls->plrY] != '1')
		{
			printf("nique move !!!!\n");
			cls->plrX += cls->dirX * moveSpeed;
		}
		if (data->map[(int)cls->plrX][(int)cls->plrY + (int)cls->dirY * (int)moveSpeed] != '1')
			cls->plrY += cls->dirY * moveSpeed;
	}
	if (keycode == 1)
	{
		if ((int)data->map[(int)cls->plrX - (int)cls->dirX * (int)moveSpeed][(int)cls->plrY] != '1')
			cls->plrX -= cls->dirX * moveSpeed;
		if ((int)data->map[(int)cls->plrX][(int)(cls->plrY - cls->dirY * moveSpeed)] != '1')
			cls->plrY -= cls->dirY * moveSpeed; 
	}
	// if (keycode == 0) //gauche
	// {
	// 	if (data->map[(int)cls->plrX + (int)cls->dirX * (int)moveSpeed][(int)cls->plrY] != '1')
	// 		cls->plrX += cls->dirX * moveSpeed;
	// 	if (data->map[(int)cls->plrX][(int)cls->plrY + (int)cls->dirY * (int)moveSpeed] != '1')
	// 		cls->plrY += cls->dirY * moveSpeed;
	// }
	// if (keycode == 2) //droite
	// {
	// 	if ((int)data->map[(int)cls->plrX - (int)cls->dirX * (int)moveSpeed][(int)cls->plrY] != '1')
	// 		cls->plrX -= cls->dirX * moveSpeed;
	// 	if ((int)data->map[(int)cls->plrX][(int)(cls->plrY - cls->dirY * moveSpeed)] != '1')
	// 		cls->plrY -= cls->dirY * moveSpeed; 
	// }
	//rotate to the right
	if (keycode == 124)
	{
		double oldDirX = cls->dirX;
		double oldPlaneX = cls->planeX;
		//both camera direction and camera plane must be rotated
		printf("dirX = dirX * cos(-0.1) - dirY * sin(-0.1) ==> %f = %f * %f - %f * %f.\n", (cls->dirX * cos(-rotSpeed) - cls->dirY * sin(-rotSpeed)), cls->dirX, cos(-rotSpeed), cls->dirY, sin(-rotSpeed));
		cls->dirX = cls->dirX * cos(-rotSpeed) - cls->dirY * sin(-rotSpeed);
		printf("dirY = oldDirX * sin(-0.1) + dirY * cos(-0.1) ==> %f = %f * %f - %f * %f.\n", (oldDirX * sin(-rotSpeed) + cls->dirY * cos(-rotSpeed)), oldDirX, sin(-rotSpeed), cls->dirY, cos(-rotSpeed));
		cls->dirY = oldDirX * sin(-rotSpeed) + cls->dirY * cos(-rotSpeed);
		printf("planeX = planeX * cos(-0.1) - planeY * sin(-0.1) ==> %f = %f * %f - %f * %f.\n", (cls->planeX * cos(-rotSpeed) - cls->planeY * sin(-rotSpeed)), cls->planeX, cos(-rotSpeed), cls->planeY, sin(-rotSpeed));
		cls->planeX = cls->planeX * cos(-rotSpeed) - cls->planeY * sin(-rotSpeed);
		printf("planeY = oldPlaneX * sin(-0.1) + planeY * cos(-0.1) ==> %f = %f * %f - %f * %f.\n", (oldPlaneX * sin(-rotSpeed) + cls->planeY * cos(-rotSpeed)), cls->planeX, sin(-rotSpeed), cls->planeY, cos(-rotSpeed));
		cls->planeY = oldPlaneX * sin(-rotSpeed) + cls->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (keycode == 123)
	{
		double oldDirX = cls->dirX;
		double oldPlaneX = cls->planeX;
		//both camera direction and camera plane must be rota@ted
		cls->dirX = cls->dirX * cos(rotSpeed) - cls->dirY * sin(rotSpeed);
		cls->dirY = oldDirX * sin(rotSpeed) + cls->dirY * cos(rotSpeed);
		cls->planeX = cls->planeX * cos(rotSpeed) - cls->planeY * sin(rotSpeed);
		cls->planeY = oldPlaneX * sin(rotSpeed) + cls->planeY * cos(rotSpeed);
	}
		mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);

	// start_raycasting(img, cls, data);
	return (1);
}
