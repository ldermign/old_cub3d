/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 08:44:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_arg *arg, t_spacemap *space)
{
	ft_memset(arg, 0, sizeof(t_arg));
	ft_memset(space, 0, sizeof(t_spacemap));
}

void 	check(int ac, char **ag)
{
	t_arg		data;
	t_spacemap	space;

	ft_check_arg(ac, ag);
	init_struct(&data, &space);
	gnl_mapcub(&data, ag[1]);
	check_wrong_data_and_recup(&data);
	recup_map(&data);
	check_map(&data, &space);
	printf_struct_arg(data, space);
	// ft_free(&data);
}

int		main(int ac, char **ag)
{
	// t_data img;
	// t_mlx a;
	// void *myStruct = NULL;
	(void)ag;
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
