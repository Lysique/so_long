/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:58:17 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/12 15:55:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	**imgs_tab(t_mlx *mlx)
{
	t_img	**sprites;
	int		x;

	x = 9;
	sprites = (t_img **)malloc(sizeof(t_img *) * x + 1);
	sprites[0] = img_init(mlx, "/map", 6);
	sprites[1] = img_init(mlx, "/walls", 8);
	sprites[2] = img_init(mlx, "/food", 3);
	sprites[3] = img_init(mlx, "/playerRun", 16);
	sprites[4] = img_init(mlx, "/playerIdle", 16);
	sprites[5] = img_init(mlx, "/ennemyIdle", 8);
	sprites[6] = img_init(mlx, "/ennemyWalk", 8);
	sprites[7] = img_init(mlx, "/ennemyAttack", 12);
	sprites[8] = img_init(mlx, "/playerDeath", 16);
	sprites[9] = 0;
	while (x)
	{
		x--;
		if (!sprites[x])
			return (free_my_sprites(sprites, mlx, x));
	}
	return (sprites);
}
