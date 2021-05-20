/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:19:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/20 13:10:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step_calculs(t_calc *clc)
{
	if (clc->rayDirX < 0)
	{
		clc->stepX = -1;
		clc->sideDistX = (clc->plrX - clc->mapX) * clc->deltaDistX;
	}
	else
	{
		clc->stepX = 1;
		clc->sideDistX = (clc->mapX + 1.0 - clc->plrX) * clc->deltaDistX;
	}
	if (clc->rayDirY < 0)
	{
		clc->stepY = -1;
		clc->sideDistY = (clc->plrY - clc->mapY) * clc->deltaDistY;
	}
	else
	{
		clc->stepY = 1;
		clc->sideDistY = (clc->mapY + 1.0 - clc->plrY) * clc->deltaDistY;
	}
}

void	which_square_with_wall_DDA(t_calc *clcls, t_arg *data)
{
	while (clcls->hit == 0)
	{
		if (clcls->sideDistX < clcls->sideDistY)
		{
			clcls->sideDistX += clcls->deltaDistX;
			clcls->mapX += clcls->stepX;
			clcls->side = 0;
		}
		else
		{
			clcls->sideDistY += clcls->deltaDistY;
			clcls->mapY += clcls->stepY;
			clcls->side = 1;
		}
		if (data->map[clcls->mapX][clcls->mapY] == '1')
			clcls->hit = 1;
	}
}

void	distance_camera_calculs(t_mlx *img, t_calc *clcls)
{
	int	lineHeight;

	if (clcls->side == 0)
		clcls->perpWallDist = (clcls->mapX - clcls->plrX
				+ (1 - clcls->stepX) / 2) / clcls->rayDirX;
	else
		clcls->perpWallDist = (clcls->mapY - clcls->plrY
				+ (1 - clcls->stepY) / 2) / clcls->rayDirY;
	lineHeight = (int)(img->height / clcls->perpWallDist);
	clcls->drawStart = -lineHeight / 2 + img->height / 2;
	clcls->drawEnd = lineHeight / 2 + img->height / 2;
	if (clcls->drawStart < 0)
		clcls->drawStart = 0;
	if (clcls->drawEnd >= img->height)
		clcls->drawEnd = img->height - 1;
}
