/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/19 17:10:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_resolution(t_arg *data, char *str)
{
	int i;

	i = 0;
	if (data->res_x != 0 && data->res_y != 0)
	{
		ft_printf("Error\nToo much info for resolution.\n");
		exit (0);
	}
	while (str[i] && space_or_element(str[i]))
		i++;
	data->res_x = ft_atoi((const char *)str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->res_y = ft_atoi((const char *)&str[i]);
	if (data->res_x <= 0 || data->res_y <= 0)
	{
		ft_printf("Error\nCheck resolution.\n");
		exit (0);
	}
}

static void	get_floor(t_arg *data, char *str)
{
	int i;

	i = 0;
	if (data->flr_r != 0 || data->flr_g != 0 || data->flr_b != 0)
	{
		ft_printf("Error\nYou've duplicated info about the floor.\n");
		exit (0);
	}
	while (str[i] && space_or_element(str[i]))
		i++;
	data->flr_r = ft_atoi((const char *)str + i);
		while (ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->flr_g = ft_atoi((const char *)str + i);
		while (ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->flr_b = ft_atoi((const char *)str + i);
}

static void	get_sky(t_arg *data, char *str)
{
	int i;

	i = 0;
	if (data->ciel_r != 0 || data->ciel_g != 0 || data->ciel_b != 0)
	{
		ft_printf("Error\nYou've duplicated info about the sky.\n");
		exit (0);
	}
	while (str[i] && space_or_element(str[i]))
		i++;
	data->ciel_r = ft_atoi((const char *)str + i);
		while (ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->ciel_g = ft_atoi((const char *)str + i);
		while (ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->ciel_b = ft_atoi((const char *)str + i);
}

char		*get_texture(char *str, char *data)
{
	int i;
	char *texture;

	i = 0;
	texture = NULL;
	if (data != NULL)
	{
		ft_printf("Error\nSome info are duplicated.\n");
		exit (0);
	}
	while (ft_is_alpha((int)str[i]) || str[i] == ' ')
		i++;
	texture = ft_strdup(&str[i]);
	return (texture);
}

void		recup_data(t_arg *data, char *str)
{
	if (ft_int_strstr(str, "R ") || ft_int_strstr(str, "F ")
	|| ft_int_strstr(str, "C ") || ft_int_strstr(str, "NO ")
	|| ft_int_strstr(str, "SO ") || ft_int_strstr(str, "WE ")
	|| ft_int_strstr(str, "EA ") || ft_int_strstr(str, "S "))
	{
		if (ft_int_strstr(str, "R "))
			get_resolution(data, str);
		else if (ft_int_strstr(str, "F "))
			get_floor(data, str);
		else if (ft_int_strstr(str, "C "))
			get_sky(data, str);
		else if (ft_int_strstr(str, "NO "))
			data->north = get_texture(str, data->north);
		else if (ft_int_strstr(str, "SO "))
			data->south = get_texture(str, data->south);
		else if (ft_int_strstr(str, "WE "))
			data->west = get_texture(str, data->west);
		else if (ft_int_strstr(str, "EA "))
			data->east = get_texture(str, data->east);
		else if (ft_int_strstr(str, "S "))
			data->sprite = get_texture(str, data->sprite);
	}
}