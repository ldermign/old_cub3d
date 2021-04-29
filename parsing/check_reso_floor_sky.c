/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reso_floor_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:03:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/29 09:27:41 by ldermign         ###   ########.fr       */
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

void	check_inside_split(t_arg *data, char **tmp)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tmp[++i])
	{
		j = 0;
		data->tmp = 0;
		while (tmp[i][j])
		{
			if (ft_isdigit(tmp[i][j]))
				data->tmp++;
			if (tmp[i][j] != '\0' || tmp[i][j] == ' '
				|| tmp[i][j] != 'F' || tmp[i][j] != 'C')
				j++;
		}
		if (data->tmp == 0)
			quit(data, "It's missing numbers in sky or floor.\n", 0, 0);
	}
	if (i != 3)
		quit(data, "It's missing some info in sky or floor.\n", 0, 0);
}

void	check_floor_sky(t_arg *data, char *str)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_split(str, ',');
	data->tmp = 0;
	while (tmp[0][j] == ' ')
		j++;
	if ((ft_strncmp(&tmp[0][j], "C ", 2) != 0)
		&& (ft_strncmp(&tmp[0][j], "F ", 2) != 0))
		quit(data, "Wrong info in sky or floor.\n", 0, 0);
	while (tmp[0][j])
	{
		if ((tmp[0][j] == 'C' || tmp[0][j] == 'F')
			|| (!ft_isdigit(tmp[0][j]) && tmp[0][j] != 'C' && tmp[0][j] != 'F'
				&& tmp[0][j] != ' ' && tmp[0][j] != '\0'
				&& tmp[0][j] != 'C' && tmp[0][j] != 'F'))
			data->tmp++;
		j++;
	}
	if (data->tmp > 1)
		quit(data, "There is some wrong info in sky of floor.\n", 0, 0);
	check_inside_split(data, tmp);
	free_str(tmp);
}
