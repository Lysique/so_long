/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:35:30 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 16:56:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_utils	*create_utils(char **map, t_mlx *mlx)
{
	t_utils	*utils;

	utils = (t_utils *)malloc(sizeof(t_utils));
	if (!utils)
		return (0);
	utils->sprites = imgs_tab(mlx);
	utils->ennemy = create_ennemy_instance(map);
	if (!utils->sprites || !utils->ennemy)
		return (0);
	utils->map = map;
	utils->mlx = mlx;
	utils->frame_loop = 0;
	utils->sprite_loop = 0;
	utils->statut = 0;
	utils->ennemy_statut = 1;
	utils->dead = 0;
	utils->side = 0;
	utils->pos = get_element_pos(utils->map, 'P');
	utils->to = utils->pos;
	utils->step = 0;
	return (utils);
}
