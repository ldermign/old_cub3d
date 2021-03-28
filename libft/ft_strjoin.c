/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:51:48 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/06 22:41:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		size_tot;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	size_tot = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if (!(dst = (char*)malloc(sizeof(char) * size_tot)))
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
