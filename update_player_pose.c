/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:01:19 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 08:57:35 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enypos(t_utils *utils, t_ennemyInstance eny, t_img *imgs)
{
	t_pos	pos;
	t_pos	to;
	t_mlx	*mlx;
	t_img	img;
	int		x;

	mlx = utils->mlx;
	x = 11;
	if (eny.side == 0)
		x = -11;
	pos.i = eny.pos.i * 64 - x;
	pos.j = eny.pos.j * 64 - 16;
	to.i = eny.to.i * 64 - x;
	to.j = eny.to.j * 64 - 16;
	x = 0;
	while (imgs[x].img)
		x++;
	x = x / 2;
	img = imgs[(eny.sprite_loop % x) + x * eny.side];
	pos.i += ((to.i - pos.i) / 6) * eny.sprite_loop;
	pos.j += ((to.j - pos.j) / 6) * eny.sprite_loop;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, pos.i, pos.j);
}

void	update_player_pose(t_utils *utils, t_img *sprites)
{
	t_pos	pos;
	t_pos	to;
	t_mlx	*mlx;
	t_img	img;

	mlx = utils->mlx;
	pos.i = utils->pos.i * 64 - 48;
	pos.j = utils->pos.j * 64 - 48;
	to.i = utils->to.i * 64 - 48;
	to.j = utils->to.j * 64 - 48;
	img = sprites[utils->sprite_loop + utils->side * 8];
	pos.i += ((to.i - pos.i) / 9) * utils->sprite_loop;
	pos.j += ((to.j - pos.j) / 9) * utils->sprite_loop;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, pos.i, pos.j);
}
