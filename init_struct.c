/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:38:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/10 19:57:20 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_agmap(t_agmap *tmp)
{
	tmp->res_x = 0;
	tmp->res_y = 0;
	tmp->flr_r = 0;
	tmp->flr_g = 0;
	tmp->flr_b = 0;
	tmp->ciel_r = 0;
	tmp->ciel_g = 0;
	tmp->ciel_b = 0;
	tmp->map = 0;
}