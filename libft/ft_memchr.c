/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:09:33 by ldermign          #+#    #+#             */
/*   Updated: 2020/11/21 23:09:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)str;
	while (n > 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		n--;
		i++;
	}
	return (NULL);
}
