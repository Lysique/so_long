/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:33:54 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:17:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_values(char **map, int e, int p, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		if (map[j][i] == 'P' && !p)
			p++;
		else if (map[j][i] == 'P')
			map[j][i] = '0';
		else if (map[j][i] == 'E')
			e = 1;
		else if (map[j][i] == 'C')
			c = 1;
		if (!map[j][++i] && ++j)
			i = 0;
	}
	if (!e || !c || !p)
		return (0);
	else
		return (1);
}

int	check_length(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (map[j])
	{
		while (map[j][i])
			i++;
		if (i != x && j != 0)
			return (0);
		x = i;
		i = 0;
		j++;
	}
	if (x > 40)
		return (0);
	if (j > 22)
		return (0);
	return (1);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !check_values(map, 0, 0, 0) || !check_length(map))
	{
		printf("Error\nBad map file and/or values\n");
		return (0);
	}
	while (map[j])
	{
		if (i == 0 || j == 0 || !map[j][i + 1] || !(map[j + 1]))
		{
			if (map[j][i] != '1')
				return (0);
		}
		i++;
		if (!map[j][i])
		{
			i = 0;
			j++;
		}
	}
	return (1);
}
