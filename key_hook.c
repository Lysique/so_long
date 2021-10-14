/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:17:43 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 08:45:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_destination(t_utils *utils)
{
	if (utils->map[utils->to.j][utils->to.i] == '1')
		return (0);
	else if (utils->map[utils->to.j][utils->to.i] == 'E')
	{
		if (!get_element_pos(utils->map, 'C').i)
		{
			utils->statut = 3;
			utils->frame_loop = 0;
			return (1);
		}
	}
	return (1);
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
	if (!check_valid_destination(utils))
	{
		utils->to = utils->pos;
		return (0);
	}
	key_update(utils);
	return (1);
}
