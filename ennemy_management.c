/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_management2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:23:46 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/01 10:23:37 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ennemy_breakpoint(t_utils *utils, t_pos enpos, t_pos ppos)
{
	int	x;

	x = 0;
	if (enpos.j == ppos.j)
	{
		if (enpos.i == ppos.i + 1 || enpos.i == ppos.i - 1)
			x = 1;
	}
	else if (enpos.i == ppos.i)
	{
		if (enpos.j == ppos.j + 1 || enpos.j == ppos.j - 1)
			x = 1;
	}
	if (x)
	{
		if (utils->statut == 0)
			utils->statut = 2;
		if (utils->ennemy_statut == 1)
			utils->ennemy_statut = 2;
		if (utils->ennemy_statut == 2 && utils->statut == 2)
			utils->frame_loop = 1;
	}
	return (x);
}

t_pos	ennemy_move(t_utils *utils, t_ennemy ennemy, int x)
{
	t_pos	pos;
	int		frame;

	pos = ennemy.pos;
	frame = utils->frame_loop + utils->sprite_loop + utils->pos.j + x;
	if (frame % 4 == 0)
		pos.i = ennemy.pos.i + 1;
	else if (frame % 4 == 1)
		pos.i = ennemy.pos.i - 1;
	else if (frame % 4 == 2)
		pos.j = ennemy.pos.j + 1;
	else
		pos.j = ennemy.pos.j - 1;
	if (utils->map[pos.j][pos.i] != '0')
	{
		if (x == 3)
			return (ennemy.pos);
		return (ennemy_move(utils, ennemy, x + 1));
	}
	utils->map[pos.j][pos.i] = 'I';
	utils->map[ennemy.pos.j][ennemy.pos.i] = '0';
	return (pos);
}

void	ennemy_run_update(t_utils *utils)
{
	int	i;

	i = 0;
	utils->ennemy_statut = 0;
	while (i < number_of_ennemies(utils->map))
	{
		utils->ennemy[i].to = ennemy_move(utils, utils->ennemy[i], 0);
		utils->ennemy[i].side = side_update(utils->ennemy[i].pos,
				utils->ennemy[i].to, utils->ennemy[i].side);
		utils->ennemy[i].sprite_loop = 0;
		i++;
	}
}

void	ennemy_run(t_utils *utils)
{
	int			i;

	if (utils->frame_loop % 500 == 0)
	{
		i = 0;
		while (i < number_of_ennemies(utils->map))
		{
			put_bg(utils->ennemy[i].pos, utils);
			put_bg(utils->ennemy[i].to, utils);
			update_ennemy_pose(utils, utils->ennemy[i], utils->sprites[7]);
			check_if_follow(utils, utils->ennemy[i]);
			utils->ennemy[i].sprite_loop++;
			if (utils->ennemy[i].sprite_loop > 6)
			{
				utils->ennemy[i].sprite_loop = 0;
				utils->ennemy[i].pos = utils->ennemy[i].to;
				utils->ennemy_statut = 1;
			}
			ennemy_breakpoint(utils, utils->ennemy[i].to, utils->to);
			i++;
		}
	}
}

void	ennemy_idle(t_utils *utils)
{
	int			i;

	if (utils->frame_loop % 1000 == 0)
	{
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
		if (utils->frame_loop % 15000 == 0 && utils->ennemy_statut == 1 && i)
			ennemy_run_update(utils);
	}
}
