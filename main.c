/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/18 15:46:29 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	check(int ac, char **ag)
{
	t_arg	data;

	ft_check_arg(ac, ag);
	ft_init_arg(&data);
	gnl_mapcub(&data, ag[1]);
	check_wrong_data(&data);
	recup_map(&data);
	check_map(&data);
	// check_final_map();
	// if (check_info_for_window(&data) == 1)
	// {
	// 	ft_printf("Error\nCheck informations in map's file.\n");
	// 	exit (0);
	// }
	printf_struct_arg(data);
	// ft_free(&data);
}

int		main(int ac, char **ag)
{
	// t_data img;
	// t_mlx a;
	// void *myStruct = NULL;
	(void)ag;
	ft_printf(KRED"\n\n\t///\\\\\\BEGINNING///\\\\\\\n\n\n"CLR_COLOR);
	check(ac, ag);


	// ft_init_img(&img);
	// img.width = 500;
	// img.height = 500;
	// a.mlx = mlx_init();
	// a.win = mlx_new_window(a.mlx, img.width, img.height, "Cub3D");
	// mlx_hook(a.win, 2, 1L<<0, ft_close, &a);
	// mlx_key_hook(a.win, key_hook, (void *)0);
	// mlx_mouse_hook(a.win, mouse_hook, &a);
	// img.img = mlx_new_image(a.mlx, img.width, img.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	// // ft_circle_pixel(img);
	// mlx_put_image_to_window(a.mlx, a.win, img.img, 0, 0);
	// mlx_loop_hook(a.mlx, render_next_frame, myStruct);
	// mlx_loop(a.mlx);
	return (0);
}
