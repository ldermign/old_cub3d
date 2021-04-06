/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:08:39 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/06 16:47:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_int(long n)
{
	int len_int;

	len_int = 0;
	if (n < 0)
		n = -n;
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
	int		len;

	nb = n;
	len = ft_len_int(nb) + (nb < 0);
	if ((dst = (char*)malloc(sizeof(char) * len + 1 + (n < 0))) == NULL)
		return (NULL);
	if (nb < 0 && (nb = -nb))
		*dst = '-';
	dst[len--] = '\0';
	while (len >= (n < 0))
	{
		dst[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}
