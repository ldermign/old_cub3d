/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/26 15:24:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(t_arg *data, char *str)
{
	int	i;

	i = 0;
	check_resolution(data, str);
	if (data->res_x != 0 && data->res_y != 0)
		quit(data, "You enter resolution more than one time.\n", 0, 0);
	while (str[i] && space_or_element(str[i]))
		i++;
	data->res_x = ft_atoi((const char *)str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->res_y = ft_atoi((const char *)&str[i]);
	if (data->res_x <= 0 || data->res_y <= 0)
		quit(data, "Check resolution.\n", 0, 0);
}

void	get_floor(t_arg *data, char *str)
{
	int	i;

	i = 0;
	check_floor_sky(data, str);
	if (data->flr_r != 0 || data->flr_g != 0 || data->flr_b != 0)
		quit(data, "You've duplicated info about the floor.\n", 0, 0);
	while (str[i] && space_or_element(str[i]))
		i++;
	data->flr_r = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->flr_g = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->flr_b = ft_atoi((const char *)str + i);
}

void	get_sky(t_arg *data, char *str)
{
	int	i;

	i = 0;
	check_floor_sky(data, str);
	if (data->ciel_r != 0 || data->ciel_g != 0 || data->ciel_b != 0)
		quit(data, "You've duplicated info about the sky.\n", 0, 0);
	while (str[i] && space_or_element(str[i]))
		i++;
	data->ciel_r = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->ciel_g = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->ciel_b = ft_atoi((const char *)str + i);
}

char	*get_texture(t_arg *data, char *str, char a, char b)
{
	int		i;
	int		len;
	char	*text;

	i = 0;
	data->tmp = 0;
	text = NULL;
	while (str[i] && (str[i] == ' ' || str[i] == a || str[i] == b))
	{
		if (str[i] == a || (str[i] == b && b != ' '))
			data->tmp++;
		i++;
	}
	if ((i < 2 && b != ' ') || (data->tmp > 2 && b != ' ') || (data->tmp > 1 && b == ' '))
		quit(data, "Something's wrong in one of the texture.\n", 0, 0);
	text = ft_strdup(&str[i]);
	len = ft_strlen(text);
	if (len <= 4 || ft_strchr(text, ' ') || text[len - 1] != 'm'
	|| text[len - 2] != 'p' || text[len - 3] != 'x' || text[len - 4] != '.' )
		quit(data, "Check name of texture.\n", 0, 0);
	return (text);
}

void	if_texture(t_arg *data, char *str)
{
	if (ft_int_strstr(str, "NO "))
	{
		if (data->north != NULL)
			quit(data, "Some info are duplicated.\n", 0, 0);
		data->north = get_texture(data, str, 'N', 'O');
	}
	if (ft_int_strstr(str, "SO "))
	{
		if (data->south != NULL)
			quit(data, "Some info are duplicated.\n", 0, 0);
		data->south = get_texture(data, str, 'S', 'O');
	}
	if (ft_int_strstr(str, "WE "))
	{
		if (data->west != NULL)
			quit(data, "Some info are duplicated.\n", 0, 0);
		data->west = get_texture(data, str, 'W', 'E');
	}
	if (ft_int_strstr(str, "EA "))
	{
		if (data->east != NULL)
			quit(data, "Some info are duplicated.\n", 0, 0);
		data->east = get_texture(data, str, 'E', 'A');
	}
}
