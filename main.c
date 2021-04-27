/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/27 14:03:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_arg *arg, t_spacemap *space)
{
	ft_memset(arg, 0, sizeof(t_arg));
	ft_memset(space, 0, sizeof(t_spacemap));
}

void	parsing(int ac, char **ag, t_arg *data)
{

	t_spacemap	space;

	ft_check_arg(ac, ag);
	init_struct(data, &space);
	gnl_mapcub(data, ag[1]);
	check_wrong_data_and_recup(data);
	recup_map(data);
	check_map(data, &space);
	printf_struct_arg(*data, space);
	// quit(&data, "All good.\n", 3, 0);
}

int		main(int ac, char **ag)
{
	t_arg data;
	t_mlx img;
	
	ft_memset(&img, 0, sizeof(t_mlx));
	parsing(ac, ag, &data);
	// img.mlx = mlx_init();
	// img.win = mlx_new_window(img.mlx, data.res_x, data.res_y, "Cub3D");
	// mlx_hook(img.win, 2, 1L<<0, ft_close, &img);
	// mlx_key_hook(img.win, key_hook, (void *)0);
	// mlx_mouse_hook(img.win, mouse_hook, &img);
	// img.img = mlx_new_image(img.mlx, data.res_x, data.res_y);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	// ft_circle_pixel(img, -400, -400, 400);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	// // mlx_loop_hook(a.mlx, render_next_frame, myStruct);
	// mlx_loop(img.mlx);

	// return (0);
}


// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);