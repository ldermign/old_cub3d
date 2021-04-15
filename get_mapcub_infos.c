/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/15 16:35:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_resolution(t_arg *data, char *str)
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

static void	get_floor(t_arg *data, char *str)
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

static void	get_sky(t_arg *data, char *str)
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

void		recup_data(t_arg *data, char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
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
		{
			if (data->north != NULL)
			{
				ft_printf("Error\nSome info are duplicated.\n");
				exit (0);
			}
			while (str[i] == 'N' || str[i] == 'O' || str[i] == ' ')
				i++;
			data->north = ft_strdup(&str[i]);
		}
		else if (ft_int_strstr(str, "SO "))
		{
			if (data->south != NULL)
			{
				ft_printf("Error\nSome info are duplicated.\n");
				exit (0);
			}
			while (str[i] == 'S' || str[i] == 'O' || str[i] == ' ')
				i++;
			data->south = ft_strdup(&str[i]);
		}
		else if (ft_int_strstr(str, "WE "))
		{
			if (data->west != NULL)
			{
				ft_printf("Error\nSome info are duplicated.\n");
				exit (0);
			}
			while (str[i] == 'W' || str[i] == 'E' || str[i] == ' ')
				i++;
			data->west = ft_strdup(&str[i]);
		}
		else if (ft_int_strstr(str, "EA "))
		{
			if (data->east != NULL)
			{
				ft_printf("Error\nSome info are duplicated.\n");
				exit (0);
			}
			while (str[i] == 'E' || str[i] == 'A' || str[i] == ' ')
				i++;
			data->east = ft_strdup(&str[i]);
		}
		else if (ft_int_strstr(str, "S "))
		{
			if (data->sprite != NULL)
			{
				ft_printf("Error\nSome info are duplicated.\n");
				exit (0);
			}
			while (str[i] == 'S' || str[i] == ' ')
				i++;
			data->sprite = ft_strdup(&str[i]);
		}
		data->tmp += 1;
	}
}