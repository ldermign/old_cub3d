/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/12 12:27:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_reso_floor_sky(t_agmap *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{ //faire check si 2 fois r ou no ou s...
		if (ft_int_strchr(data->map[i], 'R') == 1)
			get_resolution(data, ft_strchr(data->map[i], 'R'));
		if (ft_int_strchr(data->map[i], 'F') == 1)
			get_floor(data, ft_strchr(data->map[i], 'F'));
		if (ft_int_strchr(data->map[i], 'C') == 1)
			get_sky(data, ft_strchr(data->map[i], 'C'));
		i++;
	}
}

int		check_info_for_window(t_agmap *data)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;
	while (data->map[i][j])
	{
		j = 0;
		while (data->map[i][j] == ' ')
			j++;
		if (element(data->map[i][0]))
			ret++;
		if (ft_int_strstr(data->map[i], "NO")
		|| ft_int_strstr(data->map[i], "SO")
		|| ft_int_strstr(data->map[i], "WE")
		|| ft_int_strstr(data->map[i], "EA")
		|| ft_int_strstr(data->map[i], "S "))
			ret++;
		i++;
		printf("data->map[i][j] = [%c]\n", data->map[i][j]);
	}
	printf("ret = %d\n", ret);
	if (ret != 8)
		return (1);
	get_reso_floor_sky(data);
	return (0);
}

void	ft_check_save_map(char *arg)
{
	t_agmap	data;

	ft_init_agmap(&data);
	save_mapcub_in_char(&data, arg);
	// if (check_info_for_window(&data) == 1)
	// {
	// 	ft_printf("Error\nCheck informations in map's file.\n");
	// 	exit (0);
	// }
	printf_struct_arg(data);
}

void check(int ac, char **ag)
{
	ft_check_arg(ac, ag);
	ft_check_save_map(ag[1]);
}

int		main(int ac, char **ag)
{
	// t_data img;
	// t_mlx a;
	// void *myStruct = NULL;
	(void)ag;
	ft_printf("\n\t///\\\\\\BEGINNING///\\\\\\\n\n");
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
