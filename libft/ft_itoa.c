/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:08:39 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/07 14:54:12 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_int(long n)
{
	int len_int;

	len_int = 0;
	n = n < 0 ? -n : n;
	while (n >= 10)
	{
		n /= 10;
		len_int++;
	}
	return (len_int + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		neg;
	int		len;

	nb = n;
	neg = n < 0 ? 1 : 0;
	len = ft_len_int(nb);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1 + neg)))
		return (NULL);
	if (nb < 0)
		dst[0] = '-';
	len = nb < 0 ? len + 1 : len;
	nb = nb < 0 ? -nb : nb;
	dst[len] = '\0';
	len--;
	while (nb >= 10)
	{
		dst[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	dst[len] = (nb % 10) + '0';
	return (dst);
}
