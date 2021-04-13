/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:04:52 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/12 13:08:30 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (((nbr * 10) + (str[i] - '0') < nbr) && (neg == 1))
			return (-1);
		else if (((nbr * 10) + (str[i] - '0') < nbr) && (neg == -1))
			return (0);
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr *= neg;
	return (nbr);
}
