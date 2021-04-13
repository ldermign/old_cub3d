/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:39:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/13 17:50:51 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_struct_arg(t_agmap data)
{
	(void)data;
	ft_printf("\t///\\\\\\ map.cub ///\\\\\\\n");
	ft_printf("res_x = \t[%d]\n", data.res_x);
	ft_printf("res_y = \t[%d]\n", data.res_y);
	ft_printf("flr_r = \t[%d]\n", data.flr_r);
	ft_printf("flr_g = \t[%d]\n", data.flr_g);
	ft_printf("flr_b = \t[%d]\n", data.flr_b);
	ft_printf("ciel_r = \t[%d]\n", data.ciel_r);
	ft_printf("ciel_g = \t[%d]\n", data.ciel_g);
	ft_printf("ciel_b = \t[%d]\n", data.ciel_b);
	ft_printf("north = \t[%s]\n", data.north);
	ft_printf("south = \t[%s]\n", data.south);
	ft_printf("west = \t\t[%s]\n", data.west);
	ft_printf("east = \t\t[%s]\n", data.east);
	ft_printf("sprite = \t[%s]\n", data.sprite);
	// int i = 0;
	// while (data.map[i] != NULL)
	// {
	// 	printf("data->map ligne %d = \t[%s]\n", i + 1, data.map[i]);
	// 	i++;
	// }
}