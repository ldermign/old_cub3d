/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reso_floor_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:03:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/27 15:27:13 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_resolution(t_arg *data, char *str)
{
	int	i;

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

void	check_floor_sky(t_arg *data, char *str)
{
	data->tmp = 2;
	// while (*str && *str == ' ')
	// 	str++;
	// if (!ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2))
	// 	str += 2;
	// else
	// 	quit(data, "Wrong info in sky or floor.\n", 0, 0);
	// while (*str && (*str == ' ' || ft_isdigit(*str)))
	// 	str++;
	// while (*str && (*str == ' ' || *str == ','))
	// {
	// 	if (*str == ',')
	// 		data->tmp++;
	// 	str++;
	// }
	// while (*str && ft_isdigit(*str))
	// 	str++;
	// while (*str && (*str == ' ' || *str == ','))
	// {
	// 	if (*str == ',')
	// 		data->tmp++;
	// 	str++;
	// }
	// while (*str && ft_isdigit(*str))
	// 	str++;

	int i;
	int j;
	char **tmp;

	i = 0;
	j = 0;
	tmp = ft_split(str, ',');
	data->tmp = 0;
	while (tmp[0][j] == ' ')
		j++;
	if ((ft_strncmp(&tmp[0][j], "C ", 2) != 0) && (ft_strncmp(&tmp[0][j], "F ", 2) != 0))
		quit(data, "Wrong info in sky or floor.\n", 0, 0);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == ' ' || tmp[i][j] != 'F' || tmp[i][j] != 'C')
				j++;
			printf("[%s]\n", &tmp[i][j]);
			if (ft_isdigit(tmp[i][j]))
				data->tmp++;
			j++;
		}
		printf("i = %d, j = %d.\n", i, j);
		if (data->tmp == 0)
			quit(data, "It's missing numbers in sky or floor.\n", 0, 0);
		i++;
	}
	if (i != 3)
		quit(data, "Wrong info in sky or floor.\n", 0, 0);
	// if (tmp[i] < 3 || data->tmp != 2)// || *str != '\0' || !ft_isdigit(*(str - 1)))
	// 	quit(data, "Wrong info in sky or floor.\n", 0, 0);
}
