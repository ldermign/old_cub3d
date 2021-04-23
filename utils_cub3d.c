/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:25:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/23 16:50:28 by ldermign         ###   ########.fr       */
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

int		next_cara(const char *str, int c)
{
	int last_seen;

	last_seen = 0;
	while (str[last_seen])
	{
		if (str[last_seen] == (char)c)
			return (last_seen);
		last_seen++;
	}
	return (0);
}

int		pos_last(char *str, char c)
{
	int i;

	i = ft_strlen(str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (ft_strlen(str));
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

int		ft_is_player(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
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
	while (tab[i] != NULL)
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
	|| c == 'W' || c == 'E' || c == ' ');
}

int		get_position(char **tab, int c)
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
			if (tab[i][j] == (char)c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_is_texture(char *str)
{
	return (ft_int_strstr(str, "NO ")
	|| ft_int_strstr(str, "SO ") || ft_int_strstr(str, "WE ")
	|| ft_int_strstr(str, "EA ") || ft_int_strstr(str, "S "));
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


//revoir
void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int		ft_strchr_tab_wrong_cara(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!cara_in_map(tab[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strdup_map_line(char *str, int length)
{
	int		i;
	int		size;
	char	*dst;

	i = 0;
	size = ft_strlen(str);
	if (!(dst = (char*)malloc(sizeof(*dst) * (length + 1))))
		return (NULL);
	while (i < size)
	{
		dst[i] = str[i];
		i++;
	}
	while (i < length)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = (char)NULL;
	return (dst);
}

int		which_is_larger(char **tab)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		if (len < (int)ft_strlen(tab[i])
		&& !ft_is_either(tab[i]) && tab[i] != '\0')
			len = ft_strlen(tab[i]);
		i++;
	}
	return (len);
}
