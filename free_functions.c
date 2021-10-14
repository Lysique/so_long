/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:15:57 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/12 15:55:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	**free_my_sprites(t_img **sprites, t_mlx *mlx, int x)
{
	int	i;

	i = 0;
	while (x)
	{
		x--;
		if (sprites[x])
		{
			while (sprites[x][i].img)
			{
				mlx_destroy_image(mlx->mlx, sprites[x][i].img);
				i++;
			}
			i = 0;
			free(sprites[x]);
		}
	}
	free(sprites);
	return (0);
}

char	**free_my_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (0);
}

int	free_my_struct(t_img *img)
{
	free(img);
	return (0);
}

void	free_my_utils(t_utils *utils)
{
	if (utils->ennemy)
		free(utils->ennemy);
	free_my_tab(utils->map);
	free_my_sprites(utils->sprites, utils->mlx, 9);
}
