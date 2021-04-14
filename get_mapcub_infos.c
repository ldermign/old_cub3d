/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/14 17:22:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_resolution(t_agmap *data, char *str)
{
	int i;

	i = 0;
	while (str[i] && space_or_element(str[i]))
		i++;
	data->res_x = ft_atoi((const char *)str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->res_y = ft_atoi((const char *)&str[i]);
	if (data->res_x == 0 || data->res_y == 0)
	{
		ft_printf("Error\nCheck resolution.\n");
		exit (0);
	}
}

static void	get_floor(t_agmap *data, char *str)
{
	int i;

	i = 0;
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

static void	get_sky(t_agmap *data, char *str)
{
	int i;

	i = 0;
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

void		get_reso_floor_sky(t_agmap *data, char *line)
{
	int	i;

	i = 0;
	if (element(line[i]) || ft_int_strstr(&line[i], "NO ")
	|| ft_int_strstr(&line[i], "SO ") || ft_int_strstr(&line[i], "WE ")
	|| ft_int_strstr(&line[i], "EA ") || ft_int_strstr(&line[i], "S "))
	{
		if (line[i] == 'R')
			get_resolution(data, &line[i]);
		else if (line[i] == 'F')
			get_floor(data, &line[i]);
		else if (line[i] == 'C')
			get_sky(data, &line[i]);
		else if (ft_int_strstr(&line[i], "NO "))
		{
			while (line[i] == 'N' || line[i] == 'O' || line[i] == ' ')
				i++;
			data->north = ft_strdup(&line[i]);
		}
		else if (ft_int_strstr(&line[i], "SO "))
		{
			while (line[i] == 'S' || line[i] == 'O' || line[i] == ' ')
				i++;
			data->south = ft_strdup(&line[i]);
		}
		else if (ft_int_strstr(&line[i], "WE "))
		{
			while (line[i] == 'W' || line[i] == 'E' || line[i] == ' ')
				i++;
			data->west = ft_strdup(&line[i]);
		}
		else if (ft_int_strstr(&line[i], "EA "))
		{
			while (line[i] == 'E' || line[i] == 'A' || line[i] == ' ')
				i++;
			data->east = ft_strdup(&line[i]);
		}
		else if (ft_int_strstr(&line[i], "S "))
		{
			while (line[i] == 'S' || line[i] == ' ')
				i++;
			data->sprite = ft_strdup(&line[i]);
		}
		data->tmp += 1;
	}
}