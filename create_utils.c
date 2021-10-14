/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:35:30 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/12 11:41:01 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_utils	create_utils(char **map, t_mlx *mlx, t_img **sprites)
{
	t_utils	utils;

	utils.map = map;
	utils.sprites = sprites;
	utils.mlx = mlx;
	utils.frame_loop = 0;
	utils.sprite_loop = 0;
	utils.statut = 0;
	utils.ennemy_statut = 0;
	utils.side = 0;
	utils.pos = get_element_pos(utils.map, 'P');
	utils.to = utils.pos;
	utils.step = 0;
	utils.ennemy = create_ennemy_instance(map);
	if (!utils.ennemy)
	{
		free_my_utils(&utils);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (utils);
}
