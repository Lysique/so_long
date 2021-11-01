/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:18:16 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 17:44:26 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_stradd(char *map, char *buf)
{
	int		i;
	char	*c;

	i = 0;
	while (map && map[i])
		i++;
	c = (char *)malloc(i + 2);
	if (!c)
		return (free_my_string(map));
	i = 0;
	while (map && map[i])
	{
		c[i] = map[i];
		i++;
	}
	c[i++] = buf[0];
	c[i] = '\0';
	free_my_string(map);
	return (c);
}

int	nb_lines(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i++] == '\n')
			count++;
	}
	return (count);
}

char	**ft_alloc(char **tab, char *map)
{
	int	i;
	int	j;

	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (map[i] != '\n')
		i++;
	while (j < nb_lines(map))
	{
		tab[j] = (char *)malloc(i + 1);
		if (!tab[j++])
			return (free_my_tab(tab));
	}
	return (tab);
}

char	**get_tab(char *map)
{
	int		i;
	int		j;
	int		x;
	char	**tab;

	i = 0;
	j = 0;
	x = 0;
	tab = (char **)malloc(sizeof(char *) * nb_lines(map) + 1);
	tab = ft_alloc(tab, map);
	if (!tab)
		return ((char **)free_my_string(map));
	tab[nb_lines(map)] = 0;
	while (map[i])
	{
		if (map[i] == '\n' && ++i)
		{
			tab[x++][j] = '\0';
			j = 0;
		}
		else
			tab[x][j++] = map[i++];
	}
	free_my_string(map);
	return (tab);
}

char	**ber_to_tab(char *c)
{
	int		fd;
	int		ret;
	char	buf[1];
	char	*map;

	fd = check_ber(c);
	if (fd == -1)
		return (0);
	ret = 1;
	map = 0;
	while (ret == 1)
	{
		ret = read(fd, buf, 1);
		if (ret == -1 || fd < 1)
			return (0);
		if (ret)
			map = ft_stradd(map, buf);
	}
	return (get_tab(map));
}
