/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autres.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:17:09 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/03 17:18:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void ft_rainbow(t_data img)
{
	int place = 0;
	
	while (place < 800)
	{
		my_mlx_pixel_put(&img, place, place, 0x00FF0000);
		place += 5;
	}
	while (place > 0)
	{
		my_mlx_pixel_put(&img, place, 800 - place, 0x000000FF);
		place -= 5;
	}
	ft_circle(img);
}