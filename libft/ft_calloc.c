/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:04:24 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/06 17:27:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned int	len;
	unsigned char	*n;

	i = 0;
	len = nmemb * size;
	if (!(n = malloc(len)))
		return (NULL);
	while (i < len)
	{
		n[i] = 0;
		i++;
	}
	return (n);
}
