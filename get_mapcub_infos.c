/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/12 12:27:43 by ldermign         ###   ########.fr       */
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
	if (line)
		free(line);
	close(fd_map);
}



void	save_mapcub_in_char(t_agmap *data, char *arg)
{
	int		ret;
	int		call;
	int		fd_map;
	char	*line;

	ret = 1;
	fd_map = open(arg, O_RDONLY);
	line = 0;
	call = 0;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		if (element(line[0]) || (ft_int_strstr(data->map[i], "NO")
		|| ft_int_strstr(data->map[i], "SO")
		|| ft_int_strstr(data->map[i], "WE")
		|| ft_int_strstr(data->map[i], "EA")
		|| ft_int_strstr(data->map[i], "S "))
			ret++;
		call++;
	}

	if (line)
		free(line);
	close(fd_map);
	// gnl_mapcub(data, arg, fd_map, call);
}

void	get_resolution(t_agmap *data, char *str)
{
	int i;

	i = 0;
	while (str[i] && space_or_element(str[i]))
		i++;
	data->res_x = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
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