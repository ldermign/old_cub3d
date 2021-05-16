/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/16 17:42:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(int ac, char **ag)
{
	ft_check_arg(ac, ag);
	gnl_mapcub(s()->data, ag[1]);
	check_wrong_data_and_recup(s()->data);
	recup_map(s()->data);
	check_map(s()->data);
	// printf_struct_arg(*data);
	// quit(&data, "All good.\n", 3, 0);
}

int		close_escape(int keycode)
{
	if (keycode == 53)
	{
		printf("You pressed the escape button.\n");
		quit(s()->data, "Goodbye !\n", 3, 0);
		exit (0);
	}
	return (0);
}

int		close_cross()
{
	printf("You clicked on the cross.\n");
	quit(s()->data, "Goodbye !\n", 3, 0);
	exit(0);
	return (0);
}

int	print_keycode(int keycode, t_mlx *img)
{
	(void)img;
	printf("Keycode is = %d.\n", keycode);
	return (0);
}

int		move_pixel(int keycode, t_mlx *img)
{
	if (keycode == 2) //bon, d, droite
		img->x++;
	if (keycode == 1) // bon, w, haut
		img->y++;
	if (keycode == 0) // bon, a, gauche
		img->x--;
	if (keycode == 13) // bon, s, bas
		img->y--;
	my_mlx_pixel_put(img, img->x, img->y, 0x0000FF00);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int		key_press(int keycode)
{
	(void)keycode;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(keycode);
	mlx_put_image_to_window(s()->img->mlx, s()->img->win, s()->img->img, 0, 0);
	return (0);
}

int		key_release(int keycode, t_mlx *img)
{
	(void)img;
	(void)keycode;
	return (0);
}

t_s	*s(void)
{
	static t_s *stc = NULL;

	if (!stc)
	{
		stc = calloc(1, sizeof(t_s));
		if (!stc)
			return (NULL);
		stc->data = calloc(1, sizeof(t_arg));
		if (!stc->data)
			return (NULL);
		stc->img = calloc(1, sizeof(t_mlx));
		if (!stc->img)
			return (NULL);
		stc->cls = calloc(1, sizeof(t_calc));
		if (!stc->img)
			return (NULL);
	}
	return (stc);
}

int		main(int ac, char **ag)
{
	// t_arg data;
	// t_mlx img;
	// t_calc clcls;

	// free(data()->east);
	// free(data());

	parsing(ac, ag);
	get_pars(s()->data, s()->img, s()->cls);
	s()->img->mlx = mlx_init();
	s()->img->win = mlx_new_window(s()->img->mlx, s()->img->width, s()->img->height, "Cub3D");
	s()->img->img = mlx_new_image(s()->img->mlx, s()->img->width, s()->img->height);
	s()->img->addr = mlx_get_data_addr(s()->img->img, &s()->img->bpp, &s()->img->size_line, &s()->img->endian);
	start_raycasting(s()->img, s()->cls, s()->data);
	// set_keycode(&img, &clcls, &data);
	
	// mlx_hook(img.win, 2, 1L<<0, &key_press, (void *)0);
	// mlx_hook(img.win, 3, 1L<<0, &key_release, (void *)0);
	
	// PAS TOUCHER
	// mlx_key_hook(img.win, &print_keycode, &img); // ne fonctionne pas avec move pixel
	// mlx_hook(img.win, 2, 1L<<0, move_pixel, &img);
	mlx_hook(s()->img->win, 17, 1L<<0, &close_cross, (void *)0);
	mlx_key_hook(s()->img->win, &close_escape, (void *)0);


	mlx_loop(s()->img->mlx);
	return (0);
}

