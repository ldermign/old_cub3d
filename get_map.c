/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/20 15:46:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite_map(t_arg *data, char **map)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (map[i][j] && map[i + 1] && map[i][j + 1])
	{
		j++;
		if (ft_int_strchr(map[i], '2'))
		{
			j += last_zero(&map[i][j], '2');
			// printf("map[i][j] = %c\n", map [i][j]);
			// printf("map[i - 1][j] = {%c} avec i = %d et j = %d\n", map[i - 1][j], i - 1, j);
			// printf("map[i + 1][j] = {%c} avec i = %d et j = %d\n", map[i + 1][j], i + 1, j);
			// printf("map[i][j - 1] = {%c} avec i = %d et j = %d\n", map[i][j - 1], i, j - 1);
			// printf("map[i][j + 1] = {%c} avec i = %d et j = %d\n", map[i][j + 1], i, j + 1);
			if (!map[i][j] || !ft_int_strchr(map[i], '2'))
			{
				i++;
				j = 0;
			}
			if (map[i][j] == '2' && ((!map[i + 1][j])
			|| (map[i - 1][j] == ' ' || map[i][j - 1] == ' '
			|| map[i][j + 1] == ' ' || map[i + 1][j] == ' ')))
			{
				ft_printf("Error\nCheck line [%d].\n", i + 1);
				// printf("srt = {%s} avec j = %d\n", map[i], j);
				ft_print_line(data);
				exit (0);
			}
		}
	}
}

void	check_space_map(t_arg *data, char **map)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (map[i][j] && map[i + 1][j])
	{
		j++;
		if (ft_int_strchr(map[i], '0'))
		{
			j += last_zero(&map[i][j], '0');
			// printf("map[i][j] = %c\n", map [i][j]);
			if (map[i][j] == '\0' || !ft_int_strchr(map[i], '0')
			|| !map[i][j + 1])
			{
				i++;
				j = 0;
			}
			if (map[i - 1][j] && i != 0)
				printf("%d map[i - 1][j] = {%c} avec i = %d et j = %d\n", i, map[i - 1][j], i - 1, j);
			if (map[i + 1][j])
				printf("%d map[i + 1][j] = {%c} avec i = %d et j = %d\n", i, map[i + 1][j], i + 1, j);
			// if (map[i][j - 1] && j != 0)
			// 	printf("%d map[i][j - 1] = {%c} avec i = %d et j = %d\n", i, map[i][j - 1], i, j - 1);
			if (map[i][j + 1])
				printf("%d map[i][j + 1] = {%c} avec i = %d et j = %d\n", i, map[i][j + 1], i, j + 1);
			// printf("j = %d, strlen map[i]i = %d\n", i, (int)ft_strlen(map[i]));
			if (map[i][j] == '0'
			&& (map[i - 1][j] == ' ' || (j != 0 && map[i][j - 1] == ' ')
			|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '))
			{
				ft_printf("Error\nCheck line [%d].\n", i + 1);
				// printf("srt = {%s} avec j = %d\n", map[i], j);
				ft_print_line(data);
				exit (0);
			}
			printf("test\n");
		}
	}
}

void	check_map(t_arg *data)
{
	int i;
	int j;
	int len = 0;
	int size_str;

	i = 0;
	j = 0;
	len = size_tab_char(data->map_final) - 1;
	data->tmp = 0;
	if (ft_int_strchr(data->map_final[0], '0') || ft_int_strchr(data->map_final[0], '2'))
	{
		ft_printf("Error\nSomething's wrong on the first line of the map.\n");
		exit (0);
	}
	while (data->map_final[j])
	{
		if (ft_is_either(data->map_final[j]))
		{
			ft_printf("Error\nNo info at the end of the file.\n");
			exit (0);
		}
		j++;
	}
	while (data->map_final[i])
	{
		size_str = ft_strlen(data->map_final[i]) - 1;
		if (data->map_final[i][0] == '\0')
		{
			ft_printf("Error\nNo empty line, check line [ %d ]...\n", i + 1);
			ft_print_line(data);
			exit (0);
		}
		if (!ft_int_strchr(data->map_final[i], '1')
		|| ft_int_strstr(data->map_final[i], "0 ")
		|| ft_int_strstr(data->map_final[i], " 0")
		|| ft_int_strstr(data->map_final[i], "2 ")
		|| ft_int_strstr(data->map_final[i], " 2")
		|| data->map_final[i][size_str] == '0'
		|| data->map_final[i][size_str] == '2')
		{
			ft_printf("Error\nIt's missing some wall, check line [ %d ]...\n", i + 1);
			ft_print_line(data);
			exit (0);
		}
		if (ft_int_strchr(data->map_final[i], 'N')
		|| ft_int_strchr(data->map_final[i], 'S')
		|| ft_int_strchr(data->map_final[i], 'W')
		|| ft_int_strchr(data->map_final[i], 'E'))
			data->tmp++;
		i++;
	}
	if (ft_strchr_tab(data->map_final))
	{
		ft_printf("Error\nSomething's wrong in the map.\n");
		exit (0);
	}
	if (!get_position(data->map_final, 'N')
	&& !get_position(data->map_final, 'S')
	&& !get_position(data->map_final, 'E')
	&& !get_position(data->map_final, 'W'))
	{
		ft_printf("Error\nWhere is your player ? :(\n");
		exit (0);
	}
	if (ft_int_strchr(data->map_final[len], '0') || ft_int_strchr(data->map_final[len], '2'))
	{
		ft_printf("Error\nSomething's wrong on the last line of the map.\n");
		exit (0);
	}
	if (data->tmp > 1)
	{
		ft_printf("Error\nThere can be only one....\n");
		exit (0);
	}
	check_space_map(data, data->map_final);
	check_sprite_map(data, data->map_final);
}

void	ft_fill_map(t_arg *data, int len, int start, int larger)
{
	int i;

	i = 0;
	if (!(data->map_final = (char**)malloc(sizeof(char*) * (larger + 1))))
		return ;
	while (i < len)
	{
		data->map_final[i] = ft_strdup_map_line(data->fd[start], larger);
		i++;
		start++;
	}
	data->map_final[i] = NULL;
}

void	recup_map(t_arg *data)
{
	int start;
	int end;
	int len;
	int larger;
	
	start = 0;
	end = data->len_fd - 1;
	while (data->fd[start] != NULL
	&& (ft_is_either(data->fd[start]) || data->fd[start][0] == '\0'))
		start++;
	while (data->fd[end][0] == '\0')
		end--;
	len = end - start + 1;
;	if (len <= 2)
	{
		ft_printf("Error\nThis is not a map...\n");
		exit (0);
	}
	larger = which_is_larger(data->fd);
	ft_fill_map(data, len, start, larger);
}

void	check_wrong_data(t_arg *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	i = 0;
	while (data->fd[i] != NULL
	&& (ft_is_either(data->fd[i]) || data->fd[i][0] == '\0'))
	{
		recup_data(data, data->fd[i]);
		i++;
	}
	if (data->flr_r < 0 || data->flr_g < 0 || data->flr_b < 0
	|| data->ciel_r < 0 || data->ciel_g < 0 || data->ciel_b < 0
	|| data->flr_r > 255 || data->flr_g > 255 || data->flr_b > 255
	|| data->ciel_r > 255 || data->ciel_g > 255 || data->ciel_b > 255)
	{
		ft_printf("Error\nCheck floor or sky's color.\n");
		exit (0);
	}
	if (data->north == NULL || data->south == NULL || data->east == NULL
	|| data->west == NULL || data->sprite == NULL)
	{
		ft_printf("Error\nIt's missing some info.\n");
		exit (0);
	}
	if (!ft_int_strstr(data->north, ".xpm") || !ft_int_strstr(data->south, ".xpm")
	|| !ft_int_strstr(data->west, ".xpm") || !ft_int_strstr(data->east, ".xpm")
	|| !ft_int_strstr(data->sprite, ".xpm"))
	{
		ft_printf("Error\nCheck name of texture.\n");
		exit (0);
	}
}

void	save_mapcub_in_char(t_arg *data, char *arg)
{
	int		i;
	int		ret;
	int		fd_map;
	char	*line;

	i = 0;
	ret = 0;
	fd_map = open(arg, O_RDONLY);
	line = 0;
	if (!(data->fd = (char**)malloc(sizeof(char*) * (data->len_fd + 1))))
		return ;
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		data->fd[i] = ft_strdup(line);
		i++;
	}
	data->fd[i] = ft_strdup(line);
	data->fd[++i] = NULL;
	free(line);
	close(fd_map);
}

void	gnl_mapcub(t_arg *data, char *arg)
{
	int		ret;
	int		fd_map;
	char	*line;
	
	ret = 0;
	fd_map = open(arg, O_RDONLY);
	line = 0;
	if (fd_map < 0)
	{
		ft_printf("Error\nThere is no [ %s ] file.\n", arg);
		exit (0);
	}
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		if (ft_is_noting(line) && !ft_int_strchr(line, '1') && line[0] != '\0')
		{
			ft_printf("Error\nWrong info in map's file.\n", arg);
			exit (0);
		}
		data->len_fd++;
	}
	data->len_fd++;
	free(line);
	close(fd_map);
	save_mapcub_in_char(data, arg);
}