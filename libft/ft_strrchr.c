/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:15:06 by ldermign          #+#    #+#             */
/*   Updated: 2020/12/15 15:18:59 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char*)&str[i]);
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return ((char*)&str[i]);
	}
	return (NULL);
}
