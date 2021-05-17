/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:18:23 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/17 14:39:02 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keycode, t_mlx *img, t_calc *cls, t_arg *data)
{
	// cls->dirX = -1, cls->dirY = 0, cls->planeX = 0, cls->planeY = 0.66;
	// cls->dirX = -1;
	double moveSpeed = 0.1; //the constant value is in squares/second
	double rotSpeed = 0.1; //the constant value is in radians/second
	double oldDirX = cls->dirX;
	double oldPlaneX = cls->planeX;

	if (keycode == 13)
	{
		if (data->map[(int)cls->plrX + (int)cls->dirX * (int)moveSpeed][(int)cls->plrY] != '1')
			cls->plrX += cls->dirX * moveSpeed;
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
	//rotate to the right
	if (keycode == 2)
	{
		//both camera direction and camera plane must be rotated
		cls->dirX = cls->dirX * cos(-rotSpeed) - cls->dirY * sin(-rotSpeed);
		cls->dirY = oldDirX * sin(-rotSpeed) + cls->dirY * cos(-rotSpeed);
		cls->planeX = cls->planeX * cos(-rotSpeed) - cls->planeY * sin(-rotSpeed);
		cls->planeY = oldPlaneX * sin(-rotSpeed) + cls->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (keycode == 0)
	{
		//both camera direction and camera plane must be rota@ted
		cls->dirX = cls->dirX * cos(rotSpeed) - cls->dirY * sin(rotSpeed);
		cls->dirY = oldDirX * sin(rotSpeed) + cls->dirY * cos(rotSpeed);
		cls->planeX = cls->planeX * cos(rotSpeed) - cls->planeY * sin(rotSpeed);
		cls->planeY = oldPlaneX * sin(rotSpeed) + cls->planeY * cos(rotSpeed);
	}
	start_raycasting(img, cls, data);
	return (1);
}
