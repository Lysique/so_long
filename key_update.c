/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entered_key_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:07:51 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 08:21:47 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_update(t_utils *utils)
{
	t_mlx	*mlx;

	mlx = utils->mlx;
	if (utils->to.i > utils->pos.i)
		utils->side = 0;
	else if (utils->to.i < utils->pos.i)
		utils->side = 1;
	utils->sprite_loop = 0;
	utils->step++;
	put_nb_step(utils->step, utils);
	if (utils->statut == 0)
		utils->statut = 1;
}
