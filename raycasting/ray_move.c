/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:18:23 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/28 09:51:21 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int keycode, t_calc *c, t_arg *data)
{
	if (keycode == 13)
	{
		
		if (data->map[(int)(c->plrX + c->dirX * c->speed)][(int)c->plrY] != '1')
			c->plrX += c->dirX * c->speed;
		if (data->map[(int)c->plrX]
			[(int)(c->plrY + c->dirY * c->speed)] != '1')
			c->plrY += c->dirY * c->speed;
	}
	if (keycode == 1)
	{
		if (data->map[(int)(c->plrX - c->dirX * c->speed)][(int)c->plrY] != '1')
			c->plrX -= c->dirX * c->speed;
		if (data->map[(int)c->plrX]
			[(int)(c->plrY - c->dirY * c->speed)] != '1')
			c->plrY -= c->dirY * c->speed;
	}
	// if (keycode == 0) // gauche
	// {
		
	// }
	// if (keycode == 2) // droite
	// {

	// }
}

void	ft_rotation(int keycode, t_calc *c)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == 124)
	{
		oldDirX = c->dirX;
		oldPlaneX = c->planeX;
		c->dirX = c->dirX * cos(-c->rota) - c->dirY * sin(-c->rota);
		c->dirY = oldDirX * sin(-c->rota) + c->dirY * cos(-c->rota);
		c->planeX = c->planeX * cos(-c->rota) - c->planeY * sin(-c->rota);
		c->planeY = oldPlaneX * sin(-c->rota) + c->planeY * cos(-c->rota);
	}
	if (keycode == 123)
	{
		oldDirX = c->dirX;
		oldPlaneX = c->planeX;
		c->dirX = c->dirX * cos(c->rota) - c->dirY * sin(c->rota);
		c->dirY = oldDirX * sin(c->rota) + c->dirY * cos(c->rota);
		c->planeX = c->planeX * cos(c->rota) - c->planeY * sin(c->rota);
		c->planeY = oldPlaneX * sin(c->rota) + c->planeY * cos(c->rota);
	}
}

int	move_player(int keycode, t_calc *cls, t_arg *data)
{
	cls->speed = 0.1;
	cls->rota = 0.1;

	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		ft_move(keycode, cls, data);
	if (keycode == 123 || keycode == 124)
		ft_rotation(keycode, cls);
	return (1);
}
