/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 17:05:16 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_space_sprite_and_plr_map(t_arg *data, char **map, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		if (ft_int_strchr(map[i], c))
		{
			while (j < which_is_larger(map) - 1)
			{
				if (map[i][j] == c && ((i != 0 && map[i - 1][j] == ' ')
				|| (j != 0 && map[i][j - 1] == ' ')
				|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '))
					quit(data, "It's missing some wall line ", 2, i + 1);
				j++;
			}
		}
		i++;
		if (i == size_tab_char(map) - 1)
			break ;
	}
}

void	check_start_end_map(t_arg *data, char **map, int plr)
{
	int i;
	int len = 0;

	i = 0;
	len = size_tab_char(data->map_final) - 1;
	if (ft_int_strchr(map[0], plr)
	|| ft_int_strchr(map[0], '0') || ft_int_strchr(map[0], '2'))
		quit(data, "Something's wrong in the first line of the map.\n", 0, 0);
	while (map[i])
	{
		if (ft_is_either(map[i]))
			quit(data, "No info at the end of the file.\n", 0, 0);
		i++;
	}
	if (ft_int_strchr(map[0], plr)
	|| ft_int_strchr(map[len], '0') || ft_int_strchr(map[len], '2'))
		quit(data, "Something's wrong in the last line of the map.\n", 0, 0);
}

void	check_interior_map(t_arg *data, char **map, int plr)
{
	int i;
	int size_str;

	i = 0;
	while (map[i])
	{
		size_str = ft_strlen(map[i]) - 1;
		if (!ft_int_strchr(map[i], '1')
		|| map[i][0] == plr || map[i][size_str] == plr
		|| map[i][0] == '0' || map[i][size_str] == '0'
		|| map[i][0] == '2' || map[i][size_str] == '2')
			quit(data, "Check line ", 2, i + 1);
		i++;
	}
}


void	check_map(t_arg *data, t_spacemap *space)
{
	if (ft_strchr_tab_wrong_cara(data->map_final))
		quit(data, "Something's wrong in the map.\n", 0, 0);
	if (!get_position(data->map_final, 'N')
	&& !get_position(data->map_final, 'S')
	&& !get_position(data->map_final, 'E')
	&& !get_position(data->map_final, 'W'))
		quit(data, "Where is your player ? :(\n", 0, 0);
	data->tmp = how_many_player(data, data->map_final);
	if (data->tmp > 1)
		quit(data, "There can be only one....\n", 0, 0);
	space->player = return_player(data->map_final);
	check_start_end_map(data, data->map_final, space->player);
	check_interior_map(data, data->map_final, space->player);
	check_space_sprite_and_plr_map(data, data->map_final, '0');
	check_space_sprite_and_plr_map(data, data->map_final, '2');
	check_space_sprite_and_plr_map(data, data->map_final, space->player);
	get_position_player(data, space);
}

void	ft_fill_map(t_arg *data, int len, int start, int larger)
{
	int i;

	i = 0;
	if (!(data->map_final = (char**)malloc(sizeof(char*) * (len + 1))))
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
		quit(data, "This is not a map...\n", 0, 0);
	larger = which_is_larger(data->fd);
	ft_fill_map(data, len, start, larger);
}

void	check_wrong_data_and_recup(t_arg *data)
{
	int i;
	
	i = 0;
	while (data->fd[i] != NULL
	&& (ft_is_either(data->fd[i]) || data->fd[i][0] == '\0'))
	{
		recup_data(data, data->fd[i]);
		i++;
	}
	while (data->fd[i]
	&& (ft_int_strchr(data->fd[i], '1') || data->fd[i][0] == '\0'))
		i++;
	if (data->fd[i] != NULL)
		quit(data, "There is something at the end, line ", 1, i + 1);
	if (data->flr_r < 0 || data->flr_g < 0 || data->flr_b < 0
	|| data->ciel_r < 0 || data->ciel_g < 0 || data->ciel_b < 0
	|| data->flr_r > 255 || data->flr_g > 255 || data->flr_b > 255
	|| data->ciel_r > 255 || data->ciel_g > 255 || data->ciel_b > 255)
		quit(data, "Check floor or sky's color.\n", 0, 0);
	if (data->north == NULL || data->south == NULL || data->east == NULL
	|| data->west == NULL || data->sprite == NULL)
		quit(data, "It's missing some info.\n", 0, 0);
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
		quit(data, "Wrong name for .cub. Check that.\n", 0, 0);
	while ((ret = get_next_line(fd_map, &line)) > 0)
	{
		if (ft_is_noting(line) && !ft_int_strchr(line, '1') && line[0] != '\0')
			quit(data, "Something's wrong line ", 1, data->len_fd + 1);
		data->len_fd++;
	}
	data->len_fd++;
	free(line);
	close(fd_map);
	save_mapcub_in_char(data, arg);
}