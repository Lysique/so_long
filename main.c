/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:15:27 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 17:46:34 by tamighi          ###   ########.fr       */
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
	t_mlx	mlx;
	t_utils	*utils;

	if (argc != 2)
		return (0);
	map = ber_to_tab(argv[1]);
	if (!check_map(map))
	{
		free_my_tab(map);
		return (0);
	}
	mlx.mlx = mlx_init();
	new_window(&mlx, map);
	utils = create_utils(map, &mlx);
	if (!utils)
		close_game(utils);
	display_map(utils);
	mlx_key_hook(utils->mlx->win, key_hook, (void *)utils);
	mlx_hook(utils->mlx->win, 17, 1L << 2, mouse_press, (void *)utils);
	mlx_loop_hook(utils->mlx->mlx, characters_loop, (void *)utils);
	mlx_loop(utils->mlx->mlx);
}
