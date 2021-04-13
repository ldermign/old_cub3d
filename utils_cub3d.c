/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/13 15:27:33 by ldermign         ###   ########.fr       */
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

int		position_player(int c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int		strstr_double(char **str, char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (*str[k] != (char)NULL)
	{
		i = 0;
		while (str[k][i])
		{
			j = 0;
				printf("str[k][i] = %c\n", str[k][i]);
			while (needle[j] && str[k][i + j] && needle[j] == str[k][i + j])
			{
				if (needle[j + 1] == '\0')
					return (1);
				j++;
			}
			i++;
		}
		k++;
		printf("str[k] = %s\n", str[k]);
	}
	return (0);
}
