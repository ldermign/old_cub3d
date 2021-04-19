/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:39:53 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/19 14:53:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printf_struct_arg(t_arg data)
{
	(void)data;
	ft_printf(KGRN"\n\n\t///\\\\\\DATA MAP.CUB///\\\\\\\n\n\n"CLR_COLOR);
	ft_printf("res_x = \t%d\n", data.res_x);
	ft_printf("res_y = \t%d\n", data.res_y);
	ft_printf("flr_r = \t%d\n", data.flr_r);
	ft_printf("flr_g = \t%d\n", data.flr_g);
	ft_printf("flr_b = \t%d\n", data.flr_b);
	ft_printf("ciel_r = \t%d\n", data.ciel_r);
	ft_printf("ciel_g = \t%d\n", data.ciel_g);
	ft_printf("ciel_b = \t%d\n", data.ciel_b);
	ft_printf("north = \t[%s]\n", data.north);
	ft_printf("south = \t[%s]\n", data.south);
	ft_printf("west = \t\t[%s]\n", data.west);
	ft_printf("east = \t\t[%s]\n", data.east);
	ft_printf("sprite = \t[%s]\n", data.sprite);
	int i = 0;
	while (data.fd[i])
	{
		printf("\x1b[0mFile descriptor ligne [ %d ]\t\t==>\t\t\x1B[1;30m%s\n", i + 1, data.fd[i]);
		i++;
	}
	printf(KGRN"\n\n\t///\\\\\\FINAL MAP TO USE///\\\\\\\n\n\n");
	i = 0;
	while (data.map_final[i])
	{
		printf("\x1b[0mFinal map ligne [ %d ]\t\t==>\t\t\x1B[1;30m%s\n", i + 1, data.map_final[i]);
		i++;
	}
}

// void	ft_free(t_arg *data)
// {
// 	free(data->res_x);
// 	free(data->res_y);
// 	free(data->flr_r);
// 	free(data->flr_g);
// 	free(data->flr_b);
// 	free(data->ciel_r);
// 	free(data->ciel_g);
// 	free(data->ciel_b);
// 	free(data->ret);
// 	int i = 0, j = 0;
// 	while (data->map[i])
// 	{
// 		while (data->map[i][j])
// 		{
// 			free(data->map[i][j]);
// 			j++;
// 		}
// 		free(data->map[i]);
// 		i++;
// 	}
// }