/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:37:45 by ldermign          #+#    #+#             */
/*   Updated: 2021/05/13 16:34:20 by ldermign         ###   ########.fr       */
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
	// img->plrX = data->plrX;
	// img->plrY = data->plrY;
	img->map_size = size_tab_char(data->map) * ft_strlen(data->map[0]);
	img->dirX = -1;
	// img->dirY = 0;
	// img->planeX = 0;
	img->planeY = 0.66;
	// img->time = 0;
	// img->oldTime = 0;%
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

void	draw_plr(int posx, int posy, t_mlx *img)
{
	int color_plr;
	// int size_plr;

	color_plr = create_trgb(1, 1, 1, 0);
	// size_plr = taille du pint
	my_mlx_pixel_put(img, posx, posy, color_plr);
}

void 	draw_line_wall(t_mlx *img, int x, int start, int end, int side)
{
	int color;

	color = create_trgb(1, 255, 0, 0);
	if (side == 1)
		color /= 2;
	while (start < end)
	{
		my_mlx_pixel_put(img, x, start, color);
		start++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	// printf("x = %d, start = %d, end = %d\n", x, start, end);
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
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	
	// printf("map_size = %d\n", img.map_size);
	// draw_plr(img.plrX, img.plrY, &img);

	img.plrX = data.plrX, img.plrY = data.plrY;
	printf("plrX = %f, plrY = %f\n", img.plrX, img.plrY);
	img.dirX = -1, img.dirY = 0; // direction du joueur
	img.planeX = 0, img.planeY = 0.66; // plan camera du joueur

	for (int x = 0; x < img.width; x++)
	{
		// calcul position et direction du rayon
		img.cameraX = 2 * x / (double)(img.width) - 1;
		img.rayDirX = img.dirX + img.planeX * img.cameraX;
		img.rayDirY = img.dirY + img.planeY * img.cameraX;

		//which box of the map we're in
		int mapX = (int)(img.plrX);
		int mapY = (int)(img.plrY);

		//length of ray from one x or y-side to next x or y-side
		img.deltaDistX = fabs(1 / img.rayDirX);
		img.deltaDistY = fabs(1 / img.rayDirY);
		double perpWallDist;
		// Alternative code for deltaDist in case division through zero is not supported
		// img.deltaDistX = (img.rayDirY == 0) ? 0 : ((img.rayDirX == 0) ? 1 : fabs(1 / img.rayDirX));
		// img.deltaDistY = (img.rayDirX == 0) ? 0 : ((img.rayDirY == 0) ? 1 : fabs(1 / img.rayDirY));

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		printf("img.sideDistX = %f < img.sideDistY = %f\n", img.sideDistX, img.sideDistY);
		//calculate step and initial sideDist
		if (img.rayDirX < 0)
		{
			stepX = -1;
			img.sideDistX = (img.plrX - mapX) * img.deltaDistX;
		}
		else
		{
			stepX = 1;
			img.sideDistX = (mapX + 1.0 - img.plrX) * img.deltaDistX;
		}
		if (img.rayDirY < 0)
		{
			stepY = -1;
			img.sideDistY = (img.plrY - mapY) * img.deltaDistY;
		}
		else
		{
			stepY = 1;
			img.sideDistY = (mapY + 1.0 - img.plrY) * img.deltaDistY;
		}

		printf("img.sideDistX = %f < img.sideDistY = %f\n", img.sideDistX, img.sideDistY);
		//perform DDA
		hit = 0;
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (img.sideDistX < img.sideDistY)
			{
				// printf("1\n");
				img.sideDistX += img.deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				printf("2\n");
				img.sideDistY += img.deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (data.map[mapX][mapY] > 0) hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - img.plrX + (1 - stepX) / 2) / img.rayDirX;
		else
		{
			printf("ssamsaoule\n");
			perpWallDist = (mapY - img.plrY + (1 - stepY) / 2) / img.rayDirY;
		}

		//Calculate height of line to draw on screen
		// int h;
		int lineHeight;
		lineHeight = (img.height / perpWallDist);
		printf("%d = (%d / %f)\n", lineHeight, img.height, perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart;
		int drawEnd;

		drawStart = -(lineHeight / 2) + (img.height / 2);
		drawEnd = (lineHeight / 2) + (img.height / 2);
		printf("%d = -(%d / 2) + (%d / 2)\n", drawStart, lineHeight, img.height);
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= img.height)
			drawEnd = img.height - 1;

		//choose wall color
		// ColorRGB color;
		// int color;
		// switch(data.map[mapX][mapY])
		// {
		// 	case 1:  color = create_trgb(1, 255, 0, 0);  break; //red
		// 	case 2:  color = create_trgb(1, 0, 255, 0);  break; //green
		// 	case 3:  color = create_trgb(1, 0, 0, 255);   break; //blue
		// 	case 4:  color = create_trgb(1, 255, 255, 255);  break; //white
		// 	default: color = create_trgb(1, 255, 255, 0); break; //yellow
		// }

		//give x and y sides different brightness
		// if (side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		draw_line_wall(&img, x, drawStart, drawEnd, side); // refaire

		mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	}

	//timing for input and FPS counter
	// img.oldTime = img.time;
	// img.time = getTicks(); // refaire
	// double frameTime = (img.time - img.oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	// print(1.0 / frameTime); //FPS counter
	// redraw(); // pas forcement ?
	// cls(); //pas forcement ??

	// speed modifiers
	// double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
	// double rotSpeed = frameTime * 3.0; //the constant value is in radians/second


	// readKeys(); // refaire
	//move forward if no wall in front of you
	// if (keyDown(13))
	// {
	// 	if(data.map[(int)img.plrX + (int)img.dirX * (int)moveSpeed][(int)img.plrY] == 0) img.plrX += img.dirX * moveSpeed;
	// 	if(data.map[(int)img.plrX][(int)img.plrY + (int)img.dirY * (int)moveSpeed] == 0) img.plrY += img.dirY * moveSpeed;
	// }
	// //move backwards if no wall behind you
	// if (keyDown(1))
	// {
	// 	if(data.map[(int)(img.plrX - img.dirX * moveSpeed)][(int)img.plrY] == 0) img.plrX -= img.dirX * moveSpeed;
	// 	if(data.map[(int)img.plrX][(int)(img.plrY - img.dirY * moveSpeed)] == 0) img.plrY -= img.dirY * moveSpeed;
	// }
	// //rotate to the right
	// if (keyDown(2))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = img.dirX;
	// 	img.dirX = img.dirX * cos(-rotSpeed) - img.dirY * sin(-rotSpeed);
	// 	img.dirY = oldDirX * sin(-rotSpeed) + img.dirY * cos(-rotSpeed);
	// 	double oldPlaneX = img.planeX;
	// 	img.planeX = img.planeX * cos(-rotSpeed) - img.planeY * sin(-rotSpeed);
	// 	img.planeY = oldPlaneX * sin(-rotSpeed) + img.planeY * cos(-rotSpeed);
	// }
	// //rotate to the left
	// if (keyDown(0))
	// {
	// 	//both camera direction and camera plane must be rotated
	// 	double oldDirX = img.dirX;
	// 	img.dirX = img.dirX * cos(rotSpeed) - img.dirY * sin(rotSpeed);
	// 	img.dirY = oldDirX * sin(rotSpeed) + img.dirY * cos(rotSpeed);
	// 	double oldPlaneX = img.planeX;
	// 	img.planeX = img.planeX * cos(rotSpeed) - img.planeY * sin(rotSpeed);
	// 	img.planeY = oldPlaneX * sin(rotSpeed) + img.planeY * cos(rotSpeed);

	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

		


	// PAS TOUCHER
	// mlx_key_hook(img.win, &print_keycode, &img); // ne fonctionne pas avec move pixel
	mlx_key_hook(img.win, &close_escape, &data);
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

	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	mlx_loop(img.mlx);
	return (0);
}

