/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:46:18 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/15 17:25:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_arg *data)
{
	(void)data;
	int i;
	int j;
	int len = 0;

	i = 0;
	j = 0;
	len = size_tab_char(data->map);
	printf("len = %d.\n", len);
	if (ft_int_strchr(data->map[0], '0') || ft_int_strchr(data->map[len - 1], '0'))
	{
		ft_printf("Error\nSomething's wrong on the first line of the map.\n");
		exit (0);
	}
	printf("test\n");

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
	while (data->map[start] != NULL
	&& (ft_is_either(data->map[start]) || data->map[start][0] == '\0'))
		start++;
	while (data->map[end][0] == '\0')
		end--;
	len = end - start;
	printf("len_fd = %d\n", data->len_fd);
	printf("start = %d\n", start);
	printf("premiere a dupliquer = %s\n", data->map[start]);
	printf("end = %d\n", end);
	printf("derniere a dupliquer = %s\n", data->map[end]);
	printf("taille map finale = %d\n", end - start + 1);
	if ((data->map_final = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return ;
	while (i <= len)
	{
		data->map_final[i] = ft_strdup(data->map[start]);
		printf("map_final = \t%s\n", data->map_final[i]);
		i++;
		start++;
	}
	printf("i = %d\n", i);
	// data->map_final[i] = NULL;
}

void	check_wrong_data(t_arg *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		if (ft_is_noting(data->map[i]) && !ft_int_strstr(data->map[i], " 1")
		&& data->map[i][0] != '1' && data->map[i][0] != '\0')
		{
			ft_printf("Error\nSomething's wrong on line %d.\n", i + 1);
			exit (0);
		}
		i++;
	}
	i = 0;
	while (data->map[i] != NULL)
	{
		recup_data(data, data->map[i]);
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
	if (!(data->map = (char**)malloc(sizeof(char*) * (data->len_fd + 1))))
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