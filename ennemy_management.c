/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:54:00 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 09:38:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	ennemy_move(t_utils *utils, t_ennemyInstance *ennemy, int x)
{
	t_pos	pos;
	int		frame;

	pos = ennemy->pos;
	frame = utils->frame_loop + utils->sprite_loop + utils->pos.j;
	if ((frame + ennemy->pos.i) % 4 == 0)
		pos.i = ennemy->pos.i + 1;
	else if ((frame + ennemy->pos.i) % 4 == 1)
		pos.i = ennemy->pos.i - 1;
	else if ((frame + ennemy->pos.i) % 4 == 2)
		pos.j = ennemy->pos.j + 1;
	else
		pos.j = ennemy->pos.j - 1;
	if (utils->map[pos.j][pos.i] != '0')
	{
		if (x == 3)
			return (ennemy->pos);
		utils->frame_loop++;
		return (ennemy_move(utils, ennemy, x + 1));
	}
	utils->map[pos.j][pos.i] = 'I';
	utils->map[ennemy->pos.j][ennemy->pos.i] = '0';
	return (pos);
}

int	detect_player(t_utils *utils, t_ennemyInstance ennemy)
{
	int	x;

	x = 0;
	if (ennemy.to.j == utils->to.j)
	{
		if (utils->to.i == ennemy.to.i + 1 || utils->to.i == ennemy.to.i - 1)
			x = 1;
		else if (utils->to.i == ennemy.to.i && utils->statut != 4)
			x = 1;
	}
	else if (ennemy.to.i == utils->to.i)
	{
		if (utils->to.j == ennemy.to.j + 1 || utils->to.j == ennemy.to.j - 1)
			x = 1;
	}
	if (x)
		ennemy.sprite_loop = 0;
	return (x);
}

void	ennemy_update(t_utils *utils)
{
	int	i;

	i = 0;
	utils->ennemy_statut = 1;
	while (i < number_of_ennemies(utils->map))
	{
		utils->ennemy[i].to = utils->ennemy[i].pos;
		utils->ennemy[i].to = ennemy_move(utils, &utils->ennemy[i], 0);
		utils->ennemy[i].side = ennemy_side_update(utils->ennemy[i]);
		utils->ennemy[i].sprite_loop = 0;
		i++;
	}
}

void	ennemy_run(t_utils *utils)
{
	static int	x = 12500;
	int			i;

	i = 0;
	if (utils->frame_loop % x == 0)
	{
		if (x == 12500)
			ennemy_update(utils);
		x = 500;
		while (i < number_of_ennemies(utils->map))
		{
			put_bg(utils->ennemy[i].pos, utils);
			put_bg(utils->ennemy[i].to, utils);
			enypos(utils, utils->ennemy[i], utils->sprites[6]);
			utils->ennemy[i].sprite_loop++;
			if (utils->ennemy[i].sprite_loop > 6)
			{
				utils->ennemy[i].sprite_loop = 0;
				utils->ennemy[i].pos = utils->ennemy[i].to;
				x = 12500;
				utils->ennemy_statut = 0;
			}
			i++;
		}
	}
}

void	ennemy_idle(t_utils *utils)
{
	static int	x = 1000;
	int			i;

	i = 0;
	if (utils->frame_loop % x == 0)
	{
		while (i < number_of_ennemies(utils->map))
		{
			put_bg(utils->ennemy[i].pos, utils);
			enypos(utils, utils->ennemy[i], utils->sprites[5]);
			utils->ennemy[i].sprite_loop++;
			if (detect_player(utils, utils->ennemy[i]))
			{
				utils->frame_loop = 1;
				utils->statut = 2;
			}
			if (utils->ennemy[i].sprite_loop > 3)
				utils->ennemy[i].sprite_loop = 0;
			i++;
		}
	}
}
