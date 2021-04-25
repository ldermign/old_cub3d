/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:39:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/25 10:21:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_struct_arg(t_arg data, t_spacemap space)
{
	printf(KGRN"\n\t///\\\\\\DATA MAP.CUB///\\\\\\\n\n"CLR_COLOR);
	printf("res_x = \t%d\n", data.res_x);
	printf("res_y = \t%d\n", data.res_y);
	printf("flr_r = \t%d\n", data.flr_r);
	printf("flr_g = \t%d\n", data.flr_g);
	printf("flr_b = \t%d\n", data.flr_b);
	printf("ciel_r = \t%d\n", data.ciel_r);
	printf("ciel_g = \t%d\n", data.ciel_g);
	printf("ciel_b = \t%d\n", data.ciel_b);
	printf("north = \t[%s]\n", data.north);
	printf("south = \t[%s]\n", data.south);
	printf("west = \t\t[%s]\n", data.west);
	printf("east = \t\t[%s]\n", data.east);
	printf("sprite = \t[%s]\n", data.sprite);
	int i = 0;
	printf(KGRN"\n\t///\\\\\\FINAL MAP TO USE///\\\\\\\n\n");
	while (data.map[i])
	{
		printf("\x1b[0mFinal map ligne [ %d ]\t\t==>\t\t\x1B[1;30m%s\n", i + 1, data.map[i]);
		i++;
	}
	printf(KGRN"\n\t///\\\\\\DATA SPACEMAP///\\\\\\\n\n"CLR_COLOR);
	printf("player = \t%c\n", space.player);
	printf("ply_x = \t%d\n", space.ply_x);
	printf("ply_y = \t%d\n", space.ply_y);
	printf("\n");
}
