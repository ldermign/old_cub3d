/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 17:00:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_resolution(t_arg *data, char *str)
{
	int i;

	i = 0;
	data->tmp = 0;
	while (str[i] && (str[i] == 'R' || str[i] == ' '))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (data->tmp == 0)
			data->tmp = 1;
		i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (data->tmp == 1)
			data->tmp = 2;
		i++;
	}
	if (str[i] != '\0' || data->tmp != 2)
		quit(data, "Wrong info in resolution.\n", 0, 0);
}

void		check_floor_sky(t_arg *data, char *str)
{
	data->tmp = 0;
	while (*str
	&& (*str == ' ' || *str == 'F' || *str == 'C' || ft_isdigit(*str)))
		str++;
	while (*str && space_or_comma(*str))
	{
		if (*str == ',')
			data->tmp++;
		str++;
	}
	while (*str && ft_isdigit(*str))
		str++;
	while (*str && space_or_comma(*str))
	{
		if (*str == ',')
			data->tmp++;
		str++;
	}
	while (*str && ft_isdigit(*str))
		str++;
	if (data->tmp != 2 || *str != '\0')
		quit(data, "Wrong info in sky or floor.\n", 0, 0);
}

static void	get_resolution(t_arg *data, char *str)
{
	int i;

	i = 0;
	check_resolution(data, str);
	if (data->res_x != 0 && data->res_y != 0)
		quit(data, "You enter resolution more than one time.\n", 0, 0);
	while (str[i] && space_or_element(str[i]))
		i++;
	data->res_x = ft_atoi((const char *)str + i);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && space_or_comma(str[i]))
		i++;
	data->res_y = ft_atoi((const char *)&str[i]);
	if (data->res_x <= 0 || data->res_y <= 0)
		quit(data, "Check resolution.\n", 0, 0);
}

static void	get_floor(t_arg *data, char *str)
{
	int i;

	i = 0;
	check_floor_sky(data, str);
	if (data->flr_r != 0 || data->flr_g != 0 || data->flr_b != 0)
		quit(data, "You've duplicated info about the floor.\n", 0, 0);
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
	check_floor_sky(data, str);
	if (data->ciel_r != 0 || data->ciel_g != 0 || data->ciel_b != 0)
		quit(data, "You've duplicated info about the sky.\n", 0, 0);
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

char		*get_texture(t_arg *data, char *str, char *text)
{
	int		i;
	int		len;
	char	*texture;

	i = 0;
	data->tmp = 0;
	texture = NULL;
	if (text != NULL)
		quit(data, "Some info are duplicated.\n", 0, 0);
	while (str[i] && (str[i] == ' ' || str[i] == 'N' || str[i] == 'S'
	|| str[i] == 'W' || str[i] == 'E' || str[i] == 'O' || str[i] == 'A'))
	{
		i++;
		if (ft_is_alpha(str[i]))
			data->tmp++;
	}
	if (i < 3 || data->tmp >= 3)
		quit(data, "Something's wrong in one of the texture.\n", 0, 0);
	texture = ft_strdup(&str[i]);
	len = ft_strlen(texture);
	if (len <= 4 || texture[len - 1] != 'm' || texture[len - 2] != 'p'
	|| texture[len - 3] != 'x' || texture[len - 4] != '.')
		quit(data, "Check name of texture.\n", 0, 0);
	return (texture);
}

void		recup_data(t_arg *data, char *str)
{
	if (ft_is_either(str))
	{
		if (ft_int_strstr(str, "R "))
			get_resolution(data, str);
		else if (ft_int_strstr(str, "F "))
			get_floor(data, str);
		else if (ft_int_strstr(str, "C "))
			get_sky(data, str);
		else if (ft_int_strstr(str, "NO "))
			data->north = get_texture(data, str, data->north);
		else if (ft_int_strstr(str, "SO "))
			data->south = get_texture(data, str, data->south);
		else if (ft_int_strstr(str, "WE "))
			data->west = get_texture(data, str, data->west);
		else if (ft_int_strstr(str, "EA "))
			data->east = get_texture(data, str, data->east);
		else if (ft_int_strstr(str, "S "))
			data->sprite = get_texture(data, str, data->sprite);
	}
}