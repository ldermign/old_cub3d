/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:19:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/27 12:59:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_flag_len *len)
{
	write(1, &c, 1);
	len->final_len++;
}

void	ft_putstr(char *str, t_flag_len *len)
{
	size_t size;

	if (!str)
		return ;
	size = ft_strlen(str);
	write(1, str, size);
	len->final_len += (int)size;
}

void	*ft_memmove(char *dst, char *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			((char*)dst)[n - 1] = ((char*)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		size_tot;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = -1;
	size_tot = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if ((dst = (char*)malloc(sizeof(char) * size_tot)) == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
	{
		dst[i] = s2[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_atoi_printf(char *str)
{
	int i;
	int neg;
	int nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	if (str[i] == '-')
	{
		neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (neg % 2 != 0)
		nbr *= -1;
	return (nbr);
}
