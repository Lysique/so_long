/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:58:56 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:21:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_press(int keycode, t_utils *utils)
{
	(void)keycode;
	(void)utils;
	exit(0);
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
