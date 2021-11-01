/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:33:54 by tamighi           #+#    #+#             */
/*   Updated: 2021/11/01 10:09:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_return(void)
{
	printf("Error.\nBad map file and/or values.\n");
	return (0);
}

int	check_ber(char *c)
{
	int	fd;
	int	i;

	i = 0;
	while (c[i])
		i++;
	if (i < 5)
		return (-1);
	i -= 4;
	if (c[i++] != '.')
		return (-1);
	else if (c[i++] != 'b')
		return (-1);
	else if (c[i++] != 'e')
		return (-1);
	else if (c[i] != 'r')
		return (-1);
	fd = open(c, O_RDONLY);
	return (fd);
}

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
		return (error_return());
	while (map[j])
	{
		if (i == 0 || j == 0 || !map[j][i + 1] || !(map[j + 1]))
		{
			if (map[j][i] != '1')
				return (error_return());
		}
		if (map[j][i] != 'C' && map[j][i] != '1' && map[j][i] != '0'
				&& map[j][i] != 'I' && map[j][i] != 'E' && map[j][i] != 'P')
			return (error_return());
		i++;
		if (!map[j][i])
		{
			i = 0;
			j++;
		}
	}
	return (1);
}
