/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:12:56 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/13 15:01:08 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *str, size_t dstsize)
{
	size_t lendst;
	size_t i;
	size_t lenstr;

	lendst = 0;
	i = 0;
	lenstr = 0;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	while (str[lenstr])
		lenstr++;
	if (dstsize == 0)
		return (lenstr);
	while (str[i] && (lendst + i + 1) < dstsize)
	{
		dst[lendst + i] = str[i];
		i++;
	}
	if (lendst != dstsize)
		dst[lendst + i] = '\0';
	if (lendst >= dstsize)
		return (lenstr + dstsize);
	return (lendst + lenstr);
}
