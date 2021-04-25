/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reso_floor_sky.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:03:46 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/25 14:50:57 by ldermign         ###   ########.fr       */
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
	data->tmp = 0;
	while (*str
		&& (*str == ' ' || *str == 'F' || *str == 'C' || ft_isdigit(*str)))
		str++;
	while (*str && (*str == ' ' || *str == ','))
	{
		if (*str == ',')
			data->tmp++;
		str++;
	}
	while (*str && ft_isdigit(*str))
		str++;
	while (*str && (*str == ' ' || *str == ','))
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
