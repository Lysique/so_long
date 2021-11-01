/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:34:24 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 18:04:01 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fat_worm_function(t_utils *utils, t_ennemy ennemy)
{
	int		x;
	t_pos	pos;

	x = -1;
	if (ennemy.side == 0)
		x = 1;
	pos = ennemy.pos;
	pos.i += x;
	put_bg(pos, utils);
	if (utils->map[pos.j][pos.i] == 'C')
		put_collectible(pos, utils->mlx, utils->sprites[2]);
	else if (utils->map[pos.j][pos.i] == '1')
		put_walls(pos, utils->mlx, utils->sprites[1], utils->map);
}

void	ennemy_attack(t_utils *utils, t_ennemy *ennemy)
{
	ennemy->side = side_update(ennemy->pos, ennemy->to, ennemy->side);
	ennemy->to = utils->pos;
	update_ennemy_pose(utils, *ennemy, utils->sprites[8]);
	if (ennemy->sprite_loop == 5)
	{
		if (utils->pos.i == ennemy->pos.i)
			fat_worm_function(utils, *ennemy);
		put_bg(ennemy->pos, utils);
		ennemy->pos = ennemy->to;
		string_to_window(utils, "You lose !");
	}
	if (utils->pos.i == ennemy->pos.i || ennemy->sprite_loop == 7)
		fat_worm_function(utils, *ennemy);
}

void	defeat_end(t_utils *utils)
{
	int			i;
	int			x;

	i = 0;
	x = 0;
	put_bg(utils->pos, utils);
	update_player_pose(utils, utils->sprites[5]);
	if (utils->sprite_loop < 7)
		utils->sprite_loop++;
	while (i < number_of_ennemies(utils->map))
	{
		put_bg(utils->ennemy[i].pos, utils);
		if (ennemy_breakpoint(utils, utils->ennemy[i].pos, utils->to)
			&& !x++ && !utils->dead)
			ennemy_attack(utils, &utils->ennemy[i]);
		else
			update_ennemy_pose(utils, utils->ennemy[i], utils->sprites[6]);
		utils->ennemy[i].sprite_loop++;
		if (utils->ennemy[i].sprite_loop > 6)
		{
			utils->dead = 1;
			utils->ennemy[i].sprite_loop = 0;
		}
		i++;
	}
}

void	victory_end(t_utils *utils)
{
	int	i;

	i = 0;
	while (i < number_of_ennemies(utils->map))
	{
		put_bg(utils->ennemy[i].pos, utils);
		update_ennemy_pose(utils, utils->ennemy[i], utils->sprites[6]);
		utils->ennemy[i].sprite_loop++;
		if (utils->ennemy[i].sprite_loop > 3)
			utils->ennemy[i].sprite_loop = 0;
		i++;
	}
	put_bg(utils->pos, utils);
	update_player_pose(utils, utils->sprites[3]);
	utils->sprite_loop++;
	if (utils->sprite_loop > 7)
		utils->sprite_loop = 0;
	string_to_window(utils, "You Win !");
}

void	end_game(t_utils *utils)
{
	if (utils->frame_loop % 1000 == 0)
	{
		if (utils->statut == 3)
			victory_end(utils);
		else
			defeat_end(utils);
		if (utils->frame_loop == 20000)
			close_game(utils);
	}
}
