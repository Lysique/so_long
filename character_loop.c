/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:24:02 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 09:34:54 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_idle(t_utils *utils)
{
	static int	x = 1000;

	if (utils->frame_loop % x == 0)
	{
		put_bg(utils->pos, utils);
		update_player_pose(utils, utils->sprites[4]);
		utils->sprite_loop++;
		if (utils->sprite_loop > 7)
			utils->sprite_loop = 0;
	}
}

void	player_run(t_utils *utils)
{
	static int	x = 400;

	if (utils->frame_loop % x == 0)
	{
		put_bg(utils->pos, utils);
		put_bg(utils->to, utils);
		update_player_pose(utils, utils->sprites[3]);
		utils->sprite_loop++;
		if (utils->sprite_loop > 7)
		{
			utils->sprite_loop = 0;
			if (utils->map[utils->to.j][utils->to.i] == 'E')
				utils->map[utils->to.j][utils->to.i] = 'X';
			else
				utils->map[utils->to.j][utils->to.i] = 'P';
			if (utils->map[utils->pos.j][utils->pos.i] == 'X')
				utils->map[utils->pos.j][utils->pos.i] = 'E';
			else
				utils->map[utils->pos.j][utils->pos.i] = '0';
			put_bg(utils->pos, utils);
			utils->pos = utils->to;
			utils->statut = 0;
		}
	}
}

void	ennemy_loop_management(t_utils *utils)
{
	if (utils->ennemy_statut != 1)
		ennemy_idle(utils);
	ennemy_run(utils);
}

int	characters_loop(t_utils *utils)
{
	if (utils->frame_loop == 90000)
		utils->frame_loop = 0;
	utils->frame_loop++;
	if (utils->statut == 2 || utils->statut == 4)
	{
		end_time_out(utils);
		game_over(utils);
		return (1);
	}
	else if (utils->statut == 3)
	{
		end_time_out(utils);
		victory_end(utils);
		return (1);
	}
	ennemy_loop_management(utils);
	if (utils->statut == 0)
		player_idle(utils);
	else if (utils->statut == 1)
		player_run(utils);
	return (1);
}
