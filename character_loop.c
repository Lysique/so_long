/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_loop2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:19:54 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 18:03:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_breakpoint(t_utils *utils)
{
	int	i;

	i = 0;
	if (utils->map[utils->pos.j][utils->pos.i] == 'X')
	{
		if (!get_element_pos(utils->map, 'C').i)
		{
			utils->statut = 3;
			if (utils->ennemy_statut == 1)
				utils->ennemy_statut = 2;
		}
	}
	while (i < number_of_ennemies(utils->map))
		ennemy_breakpoint(utils, utils->ennemy[i++].to, utils->to);
	i = 0;
	if (utils->statut >= 2 && utils->ennemy_statut == 2)
	{
		utils->sprite_loop = 0;
		utils->frame_loop = 1;
		while (i < number_of_ennemies(utils->map))
			utils->ennemy[i++].sprite_loop = 0;
	}
}

void	player_run(t_utils *utils)
{
	if (utils->frame_loop % 400 == 0)
	{
		put_bg(utils->pos, utils);
		put_bg(utils->to, utils);
		update_player_pose(utils, utils->sprites[4]);
		utils->sprite_loop++;
		if (utils->sprite_loop > 7)
		{
			utils->sprite_loop = 0;
			put_bg(utils->pos, utils);
			utils->pos = utils->to;
			utils->statut = 0;
		}
	}
}

void	player_idle(t_utils *utils)
{	
	if (utils->frame_loop % 1000 == 0)
	{
		player_breakpoint(utils);
		put_bg(utils->pos, utils);
		update_player_pose(utils, utils->sprites[3]);
		utils->sprite_loop++;
		if (utils->sprite_loop > 7)
			utils->sprite_loop = 0;
	}
}

void	ennemy_loop_management(t_utils *utils)
{
	if (utils->ennemy_statut == 0)
		ennemy_run(utils);
	else if (utils->ennemy_statut == 1)
		ennemy_idle(utils);
}

int	characters_loop(t_utils *utils)
{
	if (utils->frame_loop++ == 90000)
		utils->frame_loop = 0;
	if (utils->statut > 1 && utils->ennemy_statut == 2)
		end_game(utils);
	else if (utils->statut == 0 || utils->statut > 1)
		player_idle(utils);
	else if (utils->statut == 1)
		player_run(utils);
	ennemy_loop_management(utils);
	return (1);
}
