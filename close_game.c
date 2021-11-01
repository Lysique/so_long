/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:58:56 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 17:19:15 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_press(t_utils *utils)
{
	close_game(utils);
	return (0);
}

void	close_game(t_utils *utils)
{
	t_mlx	mlx;

	mlx = *utils->mlx;
	free_my_utils(utils);
	mlx_destroy_window(mlx.mlx, mlx.win);
	exit(0);
}
