/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:15:27 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:09:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_window(t_mlx *mlx, char **map)
{
	int	w;
	int	h;

	w = map_length(map, 'w');
	h = map_length(map, 'h');
	mlx->win = mlx_new_window(mlx->mlx, w, h, "so_long");
}

int	main(int argc, char **argv)
{
	char	**map;
	t_img	**sprites;
	t_mlx	mlx;
	t_utils	utils;

	map = ber_to_tab(argv[1]);
	if (!check_map(map) || argc != 2)
		return ((int)free_my_tab(map));
	mlx.mlx = mlx_init();
	new_window(&mlx, map);
	sprites = imgs_tab(&mlx);
	if (!sprites)
	{
		free_my_tab(map);
		mlx_destroy_window(mlx.mlx, mlx.win);
		exit(0);
	}
	utils = create_utils(map, &mlx, sprites);
	display_map(&utils);
	put_nb_step(0, &utils);
	mlx_key_hook(utils.mlx->win, key_hook, (void *)&utils);
	mlx_hook(utils.mlx->win, 17, 1L << 2, mouse_press, &utils);
	mlx_loop_hook(utils.mlx->mlx, characters_loop, &utils);
	mlx_loop(mlx.mlx);
}
