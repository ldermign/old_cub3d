/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:18:23 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/16 17:46:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keycode)
{
	double moveSpeed = 5.0; //the constant value is in squares/second
	double rotSpeed = 3.0; //the constant value is in radians/second

	if (keycode == 13)
	{
		if(s()->data->map[(int)s()->cls->plrX + (int)s()->cls->dirX * (int)moveSpeed][(int)s()->cls->plrY] == 0) s()->cls->plrX += s()->cls->dirX * moveSpeed;
		if(s()->data->map[(int)s()->cls->plrX][(int)s()->cls->plrY + (int)s()->cls->dirY * (int)moveSpeed] == 0) s()->cls->plrY += s()->cls->dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if (keycode == 1)
	{
		if(s()->data->map[(int)(s()->cls->plrX - s()->cls->dirX * moveSpeed)][(int)s()->cls->plrY] == 0) s()->cls->plrX -= s()->cls->dirX * moveSpeed;
		if(s()->data->map[(int)s()->cls->plrX][(int)(s()->cls->plrY - s()->cls->dirY * moveSpeed)] == 0) s()->cls->plrY -= s()->cls->dirY * moveSpeed;
	}
	//rotate to the right
	if (keycode == 2)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = s()->cls->dirX;
		s()->cls->dirX = s()->cls->dirX * cos(-rotSpeed) - s()->cls->dirY * sin(-rotSpeed);
		s()->cls->dirY = oldDirX * sin(-rotSpeed) + s()->cls->dirY * cos(-rotSpeed);
		double oldPlaneX = s()->cls->planeX;
		s()->cls->planeX = s()->cls->planeX * cos(-rotSpeed) - s()->cls->planeY * sin(-rotSpeed);
		s()->cls->planeY = oldPlaneX * sin(-rotSpeed) + s()->cls->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (keycode == 0)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = s()->cls->dirX;
		s()->cls->dirX = s()->cls->dirX * cos(rotSpeed) - s()->cls->dirY * sin(rotSpeed);
		s()->cls->dirY = oldDirX * sin(rotSpeed) + s()->cls->dirY * cos(rotSpeed);
		double oldPlaneX = s()->cls->planeX;
		s()->cls->planeX = s()->cls->planeX * cos(rotSpeed) - s()->cls->planeY * sin(rotSpeed);
		s()->cls->planeY = oldPlaneX * sin(rotSpeed) + s()->cls->planeY * cos(rotSpeed);
	}
	mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
	return (1);
}
