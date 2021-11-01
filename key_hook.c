/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:17:43 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 15:22:42 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_update(t_utils *utils)
{
	t_mlx	*mlx;

	mlx = utils->mlx;
	utils->side = side_update(utils->pos, utils->to, utils->side);
	utils->sprite_loop = 0;
	utils->step++;
	put_nb_step(utils->step, utils);
	if (utils->statut == 0)
		utils->statut = 1;
	if (utils->map[utils->to.j][utils->to.i] == 'E')
		utils->map[utils->to.j][utils->to.i] = 'X';
	else
		utils->map[utils->to.j][utils->to.i] = 'P';
	if (utils->map[utils->pos.j][utils->pos.i] == 'X')
		utils->map[utils->pos.j][utils->pos.i] = 'E';
	else
		utils->map[utils->pos.j][utils->pos.i] = '0';
}

int	key_hook(int key, void *arg)
{
	t_utils	*utils;

	utils = (t_utils *)arg;
	if (key != 0 && key != 1 && key != 2 && key != 13 && key != 53)
		return (0);
	if (key == 53)
		close_game(utils);
	if (utils->statut != 0)
		return (0);
	if (key == 2)
		utils->to.i += 1;
	else if (key == 0)
		utils->to.i -= 1;
	else if (key == 1)
		utils->to.j += 1;
	else
		utils->to.j -= 1;
	if (utils->map[utils->to.j][utils->to.i] == '1')
	{
		utils->to = utils->pos;
		return (0);
	}
	key_update(utils);
	return (1);
}
