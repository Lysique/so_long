/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:01:19 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/01 09:55:57 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_follow(t_utils *utils, t_ennemy ennemy)
{
	int	i;

	i = 0;
	while (i < number_of_ennemies(utils->map))
	{
		if ((ennemy.to.i == utils->ennemy[i].to.i + 1
				|| ennemy.to.j == utils->ennemy[i].to.j + 1)
			&& utils->ennemy[i].sprite_loop != 0)
		{
			utils->ennemy[i].sprite_loop--;
			update_ennemy_pose(utils, utils->ennemy[i], utils->sprites[7]);
			utils->ennemy[i].sprite_loop++;
		}
		i++;
	}
}

void	update_ennemy_pose(t_utils *utils, t_ennemy ennemy, t_img *imgs)
{
	t_pos	pos;
	t_pos	to;
	t_mlx	*mlx;
	t_img	img;
	int		x;

	mlx = utils->mlx;
	x = 11;
	if (ennemy.side == 0)
		x = -11;
	pos.i = ennemy.pos.i * 64 - x;
	pos.j = ennemy.pos.j * 64 - 16;
	to.i = ennemy.to.i * 64 - x;
	to.j = ennemy.to.j * 64 - 16;
	x = 0;
	while (imgs[x].img)
		x++;
	x = x / 2;
	img = imgs[(ennemy.sprite_loop % x) + x * ennemy.side];
	pos.i += ((to.i - pos.i) / 6) * ennemy.sprite_loop;
	pos.j += ((to.j - pos.j) / 6) * ennemy.sprite_loop;
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
