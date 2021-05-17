/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:27:09 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/17 11:35:41 by ldermign         ###   ########.fr       */
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
	clcls->plrX = (int)data->plrX + 0.5;
	clcls->plrY = (int)data->plrY + 0.5;
}

void	init_calculs(t_mlx *img, t_calc *clcls, int i)
{
	clcls->hit = 0;
	clcls->mapX = (int)(clcls->plrX);
	clcls->mapY = (int)(clcls->plrY);
	clcls->cameraX = 2 * i / (double)(img->width) - 1;
	clcls->rayDirX = clcls->dirX + clcls->planeX * clcls->cameraX;
	clcls->rayDirY = clcls->dirY + clcls->planeY * clcls->cameraX;
	clcls->deltaDistX = fabs(1 / clcls->rayDirX);
	clcls->deltaDistY = fabs(1 / clcls->rayDirY);
}
