/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:00:58 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/11 14:00:55 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(dst = (char*)malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = (char)NULL;
	return (dst);
}
