/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:29:30 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/12 11:37:24 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit(char **map, t_mlx *mlx, t_img img)
{
	int	i;
	int	j;
	int	i2;
	int	j2;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E' || map[j][i] == 'X')
			{
				i2 = i * 64 + 16;
				j2 = j * 64 + 16;
				mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, i2, j2);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	put_bg(t_pos pos, t_utils *utils)
{
	int		i;
	int		j;
	int		rand;
	t_mlx	*mlx;
	t_img	*img;

	i = pos.i * 64;
	j = pos.j * 64;
	mlx = utils->mlx;
	img = utils->sprites[0];
	rand = pos.i % 3;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[rand].img, i, j);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[rand].img, i + 32, j);
	rand = pos.i % 3 + 1;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[rand].img, i, j + 32);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[rand].img, i + 32, j + 32);
	if (utils->map[pos.j][pos.i] == 'E' || utils->map[pos.j][pos.i] == 'X')
		put_exit(utils->map, mlx, img[5]);
}

void	put_collectible(t_pos pos, t_mlx *mlx, t_img *img)
{
	int	i;
	int	j;
	int	rand;

	i = pos.i * 64 + 16;
	j = pos.j * 64 + 16;
	rand = (pos.i + pos.j) % 3;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[rand].img, i, j);
}

void	put_walls(t_pos pos, t_mlx *mlx, t_img *img, char **map)
{
	int	i;
	int	j;
	int	x;

	i = pos.i * 64;
	j = pos.j * 64;
	x = ((pos.i / 2) + (pos.j / 3)) % 2;
	if (i == 0 || j == 0 || !map[pos.j + 1] || !map[pos.j][pos.i + 1])
		x = 0;
	x = x * 4;
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[x].img, i, j);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[x + 1].img, i + 32, j);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[x + 2].img, i, j + 32);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[x + 3].img, i + 32, j + 32);
}

void	display_map(t_utils *utils)
{
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	while (utils->map[pos.j])
	{
		while (utils->map[pos.j][pos.i])
		{
			put_bg(pos, utils);
			if (utils->map[pos.j][pos.i] == 'C')
				put_collectible(pos, utils->mlx, utils->sprites[2]);
			else if (utils->map[pos.j][pos.i] == '1')
				put_walls(pos, utils->mlx, utils->sprites[1], utils->map);
			pos.i++;
		}
		pos.i = 0;
		pos.j++;
	}
}
