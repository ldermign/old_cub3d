/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:38:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/15 17:15:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_arg(t_arg *info)
{
	info->tmp = 0;
	info->last = 0;
	info->len_fd = 0;
	info->res_x = 0;
	info->res_y = 0;
	info->flr_r = 0;
	info->flr_g = 0;
	info->flr_b = 0;
	info->ciel_r = 0;
	info->ciel_g = 0;
	info->ciel_b = 0;
	info->north = NULL;
	info->south = NULL;
	info->west = NULL;
	info->east = NULL;
	info->sprite = NULL;
	info->map = NULL;
	info->map_final = NULL;
}
