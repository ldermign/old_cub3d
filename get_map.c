/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/16 16:20:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_arg *data)
{
	int i;
	int j;
	int len = 0;

	i = 0;
	j = 0;
	len = size_tab_char(data->map_final) - 1;
	if (ft_int_strchr(data->map_final[0], '0'))
	{
		ft_printf("Error\nSomething's wrong on the first line of the map.\n");
		exit (0);
	}
	while (data->map_final[i])
	{
		if (data->map_final[i][0] == '\0')
		{
			ft_printf("Error\nNo empty line, check line [ %d ]...\n", i + 1);
			ft_print_line(data);
			exit (0);
		}
		if (!ft_int_strchr(data->map_final[i], '1')
		|| ft_int_strstr(data->map_final[i], "0 ")
		|| ft_int_strstr(data->map_final[i], " 0"))
		{
			ft_printf("Error\nIt's missing some wall, check line [ %d ]...\n", i + 1);
			ft_print_line(data);
			exit (0);
		}
		i++;
	}
	if (!get_position(data->map_final, 'N')
	&& !get_position(data->map_final, 'S')
	&& !get_position(data->map_final, 'E')
	&& !get_position(data->map_final, 'W'))
	{
		ft_printf("Error\nWhere is your player ? :(\n");
		exit (0);
	}
	// else (get position)
	if (ft_int_strchr(data->map_final[len], '0'))
	{
		ft_printf("Error\nSomething's wrong on the last line of the map.\n");
		exit (0);
	}
}

void	recup_map(t_arg *data)
{
	int i;
	int start;
	int end;
	int len;
	
	i = 0;
	start = 0;
	end = data->len_fd - 1;
	while (data->fd[start] != NULL
	&& (ft_is_either(data->fd[start]) || data->fd[start][0] == '\0'))
		start++;
	while (data->fd[end][0] == '\0')
		end--;
	len = end - start + 1;
	if ((data->map_final = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return ;
	while (i < len)
	{
		data->map_final[i] = ft_strdup(data->fd[start]);
		i++;
		start++;
	}
	data->map_final[i] = NULL;
}

void	check_wrong_data(t_arg *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	// while (data->fd[i] != NULL)
	// {
	// 	if (ft_is_noting(data->fd[i])// && !ft_int_strstr(data->fd[i], " 1")
	// 	&& !ft_int_strchr(data->fd[i], '1') && data->fd[i][0] != '\0')
	// 	{
	// 		ft_printf("Error\nSomething's wrong on line %d.\n", i + 1);
	// 		exit (0);
	// 	}
	// 	i++;
	// }
	i = 0;
	while (data->fd[i] != NULL)
	{
		recup_data(data, data->fd[i]);
		i++;
	}
}

void	gnl_mapcub(t_arg *data, char *arg) //, int skip)
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
		if (ft_is_noting(line) || !ft_int_strstr(line, " 1")
		|| !ft_int_strchr(line, '1') || line[0] != '\0')
		{
			data->fd[i] = ft_strdup(line);
			i++;
		}
		else
		{
			ft_printf("Error\nSomething's wrong on line %d.\n", i + 1);
			exit (0);
		}
	}
	data->fd[i] = ft_strdup(line);
	data->fd[++i] = NULL;
	free(line);
	close(fd_map);
}

void	save_mapcub_in_char(t_arg *data, char *arg)
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
		data->len_fd++;
	data->len_fd++;
	free(line);
	close(fd_map);
	gnl_mapcub(data, arg);
}