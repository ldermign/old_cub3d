/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:14:31 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/06 23:03:17 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && i < size)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < size)
		{
			if (s2[j + 1] == '\0')
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
