/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/15 16:53:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_int_strstr(char *str, char *needle)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (needle[j] == str[i + j])
		{
			if (needle[j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	if (str[i])
		return (0);
	return (0);
}

int		ft_int_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if (str[i] || (char)c == '\0')
		return (0);
	return (0);
}

int		space_or_element(int c)
{
	return (c == ' ' || c == 'R' || c == 'F' || c == 'C');
}

int		space_or_comma(int c)
{
	return (c == ' ' || c == ',');
}

int		element(int c)
{
	return (c == 'R' || c == 'F' || c == 'C');	
}

int		pos_player(int c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int		full_of(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int		size_tab_char(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int		ft_is_map(char c)
{
	return (c == ' ' || c == '1');
}

int		cara_in_map(int c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
	|| c == 'E' || c == 'W');
}

void		map_valid(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (!cara_in_map(tab[i][j]) || tab[i][j] != ' ')
			{
				ft_printf("Error\nThe element [ %c ] line [ %d ] is not valid.\n", tab[i][j], i);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int		ft_is_noting(char *str)
{
	return (!ft_int_strstr(str, "R ") && !ft_int_strstr(str, "F ")
	&& !ft_int_strstr(str, "C ") && !ft_int_strstr(str, "NO ")
	&& !ft_int_strstr(str, "SO ") && !ft_int_strstr(str, "WE ")
	&& !ft_int_strstr(str, "EA ") && !ft_int_strstr(str, "S "));
}

int		ft_is_either(char *str)
{
	return (ft_int_strstr(str, "R ") || ft_int_strstr(str, "F ")
	|| ft_int_strstr(str, "C ") || ft_int_strstr(str, "NO ")
	|| ft_int_strstr(str, "SO ") || ft_int_strstr(str, "WE ")
	|| ft_int_strstr(str, "EA ") || ft_int_strstr(str, "S "));
}