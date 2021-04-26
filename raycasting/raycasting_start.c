/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:46:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/26 11:49:01 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mouse_hook(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	return (0);
}

int		key_hook(int keycode, void *param)
{
	(void)param;
	(void)keycode;
	// printf("keycode is [%d].\n", keycode);
	return (0);
}

int		ft_close(int keycode, t_mlx *temp)
{
	(void)temp;
	(void)keycode;
	if (keycode == 53)
	{
		printf("Goodbye !\n");
		exit(0);
	}
	return (0);
}