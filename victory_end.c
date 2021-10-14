/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:56:09 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 08:50:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory_end(t_utils *utils)
{
	static int	x = 400;

	if (utils->frame_loop % x == 0)
	{
		put_bg(utils->to, utils);
		if (x == 400)
		{
			put_bg(utils->pos, utils);
			update_player_pose(utils, utils->sprites[3]);
		}
		else
		{
			update_player_pose(utils, utils->sprites[4]);
			string_to_window(utils, "You win");
		}
		utils->sprite_loop++;
		if (utils->sprite_loop > 7)
		{
			if (x == 400)
				put_bg(utils->pos, utils);
			x = 1000;
			utils->pos = utils->to;
			utils->sprite_loop = 0;
		}
	}
}
