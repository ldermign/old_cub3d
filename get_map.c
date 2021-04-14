/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/14 17:47:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_agmap *data)
{
	(void)data;
	int i;
	int j;
	int len = 0;

	i = 0;
	j = 0;
	len = size_tab_char(data->map);
	printf("len = %d.\n", len);
	// if (!full_of(data->map[0], '1'))
	// {
	// 	ft_printf("Error\nSomething's wrong on the first line of the map.\n");
	// 	exit (0);
	// }

}

void	gnl_mapcub(t_agmap *data, char *arg, int len_map, int skip)
{
	int 	i;
	int 	j;
	int		ret;
	int 	fd_map;
	char	*line;

	i = 0;
	j = 0;
	ret = 0;
	line = 0;
	fd_map = open(arg, O_RDONLY);
	if ((data->map = (char**)malloc(sizeof(char*) * (len_map - skip + 1))) == NULL)
		return ;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		printf("j = %d\n", j);
		// printf("element = %d\n", element(line[0]));
		if ((j <= len_map - skip) && line[0] != '\0'
		&& (!element(line[0]) && !ft_int_strstr(line, "NO ")
		&& !ft_int_strstr(line, "SO ") && !ft_int_strstr(line, "WE ")
		&& !ft_int_strstr(line, "EA ") && !ft_int_strstr(line, "S ")))
		{
			data->map[j] = ft_strdup(line);
			j++;
		}
		i++;
	}
	if (line[0] != '\0')
	{
		data->map[j] = ft_strdup(line);
		j++;
	}
	data->map[j] = NULL;
	free(line);
	close(fd_map);
}

void	save_mapcub_in_char(t_agmap *data, char *arg)
{
	int		ret;
	int		skip;
	int		fd_map;
	int		len_map;
	char	*line;

	ret = 0;
	skip = 0;
	fd_map = open(arg, O_RDONLY);
	len_map = 0;
	line = 0;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		if (data->tmp != 8 || line[0] == '\0')
			skip++;
		get_reso_floor_sky(data, line);
		len_map++;
	}
	if (line[0] != '\0')
		len_map++;
	skip++;
	len_map++;
	free(line);
	close(fd_map);
	if (data->tmp != 8)
	{
		if (data->tmp > 8)
			ft_printf("Error\nToo much info in map's file.\n");
		if (data->tmp < 8)
			ft_printf("Error\nIt's missing some info in map's file.\n");
		exit (0);
	}
	gnl_mapcub(data, arg, len_map, skip);
}