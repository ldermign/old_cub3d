/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/13 17:50:48 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	gnl_mapcub(t_agmap *data, char *arg, int fd_map, int call)
{
	int		i;
	int 	ret;
	char	*line;

	i = 0;
	ret = 1;
	line = 0;
	fd_map = open(arg, O_RDONLY);
	if ((data->map = (char**)malloc(sizeof(char*) * (call + 2))) == NULL)
		return ;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		data->map[i] = ft_strdup(line);
		i++;
	}
	data->map[i] = ft_strdup(line);
	data->map[++i] = NULL;
	free(line);
	close(fd_map);
}

int		get_reso_floor_sky(t_agmap *data, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R' || line[i] == 'F' || line[i] == 'C'
	|| ft_int_strstr(&line[i], "NO ") || ft_int_strstr(&line[i], "SO ")
	|| ft_int_strstr(&line[i], "WE ") || ft_int_strstr(&line[i], "EA ")
	|| ft_int_strstr(&line[i], "S "))
	{
		if (line[i] == 'R')
			get_resolution(data, &line[i]);
		else if (line[i] == 'F')
			get_floor(data, &line[i]);
		else if (line[i] == 'C')
			get_sky(data, &line[i]);
		else if (ft_int_strstr(&line[i], "NO "))
			data->north = ft_strdup(&line[i + 3]);
		else if (ft_int_strstr(&line[i], "SO "))
			data->south = ft_strdup(&line[i + 3]);
		else if (ft_int_strstr(&line[i], "WE "))
			data->west = ft_strdup(&line[i + 3]);
		else if (ft_int_strstr(&line[i], "EA "))
			data->east = ft_strdup(&line[i + 3]);
		else if (ft_int_strstr(&line[i], "S "))
			data->sprite = ft_strdup(&line[i + 2]);
		data->ret += 1;
		return (1);
	}
	return (0);
}

void	save_mapcub_in_char(t_agmap *data, char *arg)
{
	int		ret;
	int		len_map;
	int		fd_map;
	char	*line;

	ret = 1;
	fd_map = open(arg, O_RDONLY);
	line = 0;
	len_map = 0;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		if (line != NULL && get_reso_floor_sky(data, line) == 0)
			len_map++;
	}
	free(line);
	close(fd_map);
	if (data->ret != 8)
	{
		if (data->ret > 8)
			ft_printf("Error\nToo much info in map's file.\n");
		if (data->ret < 8)
			ft_printf("Error\nIt's missing some info in map's file.\n");
		exit (0);
	}
	// gnl_mapcub(data, arg, fd_map, call);
}

void	get_resolution(t_agmap *data, char *str)
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
}

void	get_floor(t_agmap *data, char *str)
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

void	get_sky(t_agmap *data, char *str)
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