/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/06 14:21:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(int ac, char **ag, t_arg *data)
{
	ft_check_arg(ac, ag);
	ft_memset(data, 0, sizeof(t_arg));
	gnl_mapcub(data, ag[1]);
	check_wrong_data_and_recup(data);
	recup_map(data);
	check_map(data);
	// printf_struct_arg(*data);
	// quit(&data, "All good.\n", 3, 0);
}

void	get_pars(t_arg *data, t_mlx *img)
{
	ft_memset(img, 0, sizeof(t_mlx));
	img->width = data->res_x;
	img->height = data->res_y;
	img->sky = create_trgb(1, data->ciel_r, data->ciel_g, data->ciel_b);
	img->floor = create_trgb(1, data->flr_r, data->flr_g, data->flr_b);
	img->plrX = data->plrX;
	img->plrY = data->plrY;
	img->dirX = -1;
	// img->dirY = 0;
	// img->planeX = 0;
	img->planeY = 0.66;
	// img->time = 0;
	// img->oldTime = 0;
}

int		close_escape(int keycode, t_arg *data)
{
	if (keycode == 53)
	{
		printf("You pressed the escape button.\n");
		quit(data, "Goodbye !\n", 3, 0);
		exit(0);
	}
	return (0);
}

int		close_cross(t_arg *data)
{
	printf("You clicked on the cross.\n");
	quit(data, "Goodbye !\n", 3, 0);
	exit(0);
	return (0);
}

int	print_keycode(int keycode, t_mlx *img)
{
	(void)img;
	printf("Keycode is = %d.\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int 	afficher_coor_souris(t_mlx *img)
{
	(void)img;
	// printf("x = %d, y = %d.\n", );
	return (0);
}

int 	souris_entree()
{
	printf("Congrats ! You entered in the window...\n");
	return (0);
}

int 	souris_sortie(t_mlx *img)
{
	(void)img;
	printf("You are leaving so soon...\n");
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

int		key_press(int keycode, t_mlx *img)
{
	(void)keycode;
	(void)img;
	return (0);
}

int		key_release(int keycode, t_mlx *img)
{
	(void)keycode;
	(void)img;
	return (0);
}

int		mouse_press(int keycode, int x, int y, t_mlx *img)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)img;
	return (0);
}

int		mouse_release(int keycode, int x, int y, t_mlx *img)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)img;
	return (0);
}

int		mouse_motion(int x, int y, t_mlx *img)
{
	(void)x;
	(void)y;
	(void)img;
	return (0);
}

void	set_key_code(t_mlx *img)
{
	(void)img;
	mlx_hook(img->win, 2, 0, key_press, img);
	mlx_hook(img->win, 3, 0, key_release, img);
	mlx_hook(img->win, 4, 0, mouse_press, img);
	mlx_hook(img->win, 5, 0, mouse_release, img);
	mlx_hook(img->win, 6, 0, mouse_motion, img);
	// mlx_hook(img->win, 12, 0, expose, img);
	// mlx_hook(img->win, 17, 0, exit_hook, img);
}

int		main(int ac, char **ag)
{
	t_arg data;
	t_mlx img;
	
	ft_memset(&img, 0, sizeof(t_mlx));
	parsing(ac, ag, &data);
	get_pars(&data, &img);

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);

	fill_sky_and_floor(&img);



	while (!done())
	{
		for (int x = 0; x < w; x++)
		{
			// calcul position et direction du rayon
			img.cameraX = 2 * x / (double(w)) - 1;
			img.rayDirX = img.dirX + img.planeX * img.cameraX;
			img.rayDirY = img.dirY + img.planeX * img.cameraX;
			//which box of the map we're in
    		img.mapX = int(img.posX);
    		img.mapY = int(img.posY);

    		//length of ray from current position to next x or y-side
    		img.sideDistX;
    		img.sideDistY;

    		 //length of ray from one x or y-side to next x or y-side
    		img.deltaDistX = std::abs(1 / rayDirX);
    		img.deltaDistY = std::abs(1 / rayDirY);
    		double perpWallDist;

    		//what direction to step in x or y-direction (either +1 or -1)
    		int stepX;
    		int stepY;

    		int hit = 0; //was there a wall hit?
    		int side; //was a NS or a EW wall hit?
		}

	}



	// PAS TOUCHER
	// mlx_key_hook(img.win, &print_keycode, &img); // ne fonctionne pas avec move pixel
	// mlx_key_hook(img.win, &close_escape, &data);
	mlx_hook(img.win, 2, 1L<<0, move_pixel, &img);
	mlx_hook(img.win, 17, 1L<<0, &close_cross, &data);


	// TEST
	// mlx_mouse_hook(img.win, afficher_coor_souris, &img);
	// mlx_hook(img.win, 2, 1L<<0, move_pixel, &img); // fonctionne avec 2 et 1L<<0 mais pas escape
	// mlx_hook(img.win, 7, 1L<<4, souris_entree, (void *)0);
	// mlx_hook(img.win, 8, 1L<<5, souris_sortie, (void *)0);
	// mlx_hook(img.win, 6, 1L<<6, afficher_coor_souris, &img);
	// mlx_key_hook(img.win, move_pixel, &img);
	// mlx_loop_hook(a.mlx, render_next_frame, myStruct);

	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	mlx_loop(img.mlx);
	return (0);
}

