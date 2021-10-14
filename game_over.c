/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:28:14 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:26:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_time_out(t_utils *utils)
{
	static int	x = 20000;

	if (utils->frame_loop % x == 0)
		close_game(utils);
}

void	player_death(t_utils *utils)
{
	put_bg(utils->pos, utils);
	update_player_pose(utils, utils->sprites[8]);
	if (utils->sprite_loop < 7)
		utils->sprite_loop++;
}

void	attack_scene(t_utils *utils, t_ennemyInstance *ennemy)
{
	put_bg(ennemy->to, utils);
	ennemy->to = utils->to;
	ennemy->side = ennemy_side_update(*ennemy);
	if (ennemy->pos.j == utils->to.j)
		enypos(utils, *ennemy, utils->sprites[7]);
	else
		enypos(utils, *ennemy, utils->sprites[6]);
	ennemy->sprite_loop++;
	if (ennemy->sprite_loop == 6)
	{
		put_bg(ennemy->pos, utils);
		utils->map[ennemy->pos.j][ennemy->pos.i] = '0';
		utils->map[ennemy->to.j][ennemy->to.i] = 'I';
		ennemy->pos = ennemy->to;
		utils->statut = 4;
		string_to_window(utils, "You lose");
	}
}

void	game_over(t_utils *utils)
{
	static int	x = 600;
	int			y;
	int			i;

	i = 0;
	y = 0;
	if (utils->frame_loop % x == 0)
	{
		player_death(utils);
		while (i < number_of_ennemies(utils->map))
		{
			put_bg(utils->ennemy[i].pos, utils);
			if (detect_player(utils, utils->ennemy[i]) && !y++)
				attack_scene(utils, &utils->ennemy[i]);
			else
			{
				enypos(utils, utils->ennemy[i], utils->sprites[5]);
				utils->ennemy[i].sprite_loop++;
			}
			if (utils->ennemy[i].sprite_loop == 6)
				utils->ennemy[i].sprite_loop = 0;
			i++;
		}
	}
}
