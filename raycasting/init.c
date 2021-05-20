/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:27:09 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/20 13:38:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pars(t_arg *data, t_mlx *img, t_calc *clcls)
{
	ft_memset(img, 0, sizeof(t_mlx));
	ft_memset(clcls, 0, sizeof(t_calc));
	img->width = data->res_x;
	img->height = data->res_y;
	img->sky = create_trgb(1, data->ciel_r, data->ciel_g, data->ciel_b);
	img->floor = create_trgb(1, data->flr_r, data->flr_g, data->flr_b);
	clcls->plrX = (int)data->plrX;
	clcls->plrY = (int)data->plrY;
}

void	texture(t_mlx *img, t_calc *clcls, t_arg *data)
{
	(void)img;
	(void)clcls;
	(void)data;
	// int i;

	// i = 0;
	// vector<Uint32> texture[8];
	// while ()
  	// for(int i = 0; i < 8; i++) texture[i].resize(texWidth * texHeight);
}

void	init_calculs(t_mlx *img, t_calc *clcls, int i)
{
	clcls->hit = 0;
	clcls->mapX = (int)(clcls->plrX);
	clcls->mapY = (int)(clcls->plrY);
	clcls->cameraX = 2 * i / (double)(img->width) - 1;
	clcls->rayDirX = clcls->dirX + clcls->planeX * clcls->cameraX;
	clcls->rayDirY = clcls->dirY + clcls->planeY * clcls->cameraX;
	if (clcls->rayDirX == 0)
		clcls->deltaDistY = 0;
	else
		clcls->deltaDistX = fabs(1 / clcls->rayDirX);
	if (clcls->rayDirY == 0)
		clcls->deltaDistY = 0;
	else
		clcls->deltaDistY = fabs(1 / clcls->rayDirY);
	// texture(img, clcls, s()->data);
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
