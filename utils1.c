/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:22:50 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 15:00:39 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	side_update(t_pos from, t_pos to, int side)
{
	if (from.i < to.i)
		return (0);
	else if (from.i > to.i)
		return (1);
	else
		return (side);
}

void	string_to_window(t_utils *utils, char *string)
{
	t_mlx	*mlx;
	int		h;

	h = map_length(utils->map, 'h') - 44;
	mlx = utils->mlx;
	mlx_string_put(mlx->mlx, mlx->win, 15, h, 0x00FF0000, string);
}

t_pos	get_element_pos(char **map, char element)
{
	t_pos	pos;

	pos.i = 0;
	pos.j = 0;
	while (map[pos.j])
	{
		while (map[pos.j][pos.i])
		{
			if (map[pos.j][pos.i] == element)
				return (pos);
			pos.i++;
		}
		pos.i = 0;
		pos.j++;
	}
	if (element == 'P' || element == 'E')
		return (get_element_pos(map, 'X'));
	return (pos);
}

int	map_length(char **map, char axis)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
			i++;
		if (axis == 'w')
			return (i * 64);
		j++;
	}
	return (j * 64);
}
