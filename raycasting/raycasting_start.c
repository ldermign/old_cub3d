/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/28 09:57:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void 	draw_line_wall(int x, int start, int end, int side)
{
	int	color;

	color = create_trgb(1, 255, 255, 255);
	if (side == 1)
		color = create_trgb(1, 200, 50, 100);
	while (start < end)
	{
		my_mlx_pixel_put(s()->img, x, start, color);
		start++;
		// if (x == 249 || x == 250 || x == 251)
		// 	printf("x = [%d].", x);
	}
}

int	all_calculs_cub(t_mlx *img, t_calc *cls, t_arg *data)
{
	int	i;

	i = 0;
	fill_sky_and_floor(img);
	while (i < img->width)
	{
		init_calculs(img, cls, i);
		step_calculs(cls);
		which_square_with_wall_DDA(cls, data);
		distance_camera_calculs(img, cls);
		draw_line_wall(i, cls->drawStart, cls->drawEnd, cls->side);
		i++;
	}
	mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
	return (0);
}
