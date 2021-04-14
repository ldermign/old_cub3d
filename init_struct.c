/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:38:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/14 16:55:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_agmap(t_agmap *info)
{
	info->res_x = 0;
	info->res_y = 0;
	info->flr_r = 0;
	info->flr_g = 0;
	info->flr_b = 0;
	info->ciel_r = 0;
	info->ciel_g = 0;
	info->ciel_b = 0;
	info->tmp = 0;
	// info->north = NULL;
	// info->south = NULL;
	// info->west = NULL;
	// info->east = NULL;
	// info->sprite = NULL;
	// info->map = 0;
}
