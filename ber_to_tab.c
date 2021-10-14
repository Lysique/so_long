/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:48:33 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:17:13 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	j = 0;
	if (!tab)
		return (0);
	while (map[i] != '\n')
		i++;
	while (j < nb_lines(map))
	{
		tab[j] = (char *)malloc(i + 1);
		if (!tab[j])
			return (free_my_tab(tab));
		j++;
	}
	return (tab);
}

char	**get_tab(char *map)
{
	int		i;
	char	**tab;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	tab = (char **)malloc(sizeof(char *) * nb_lines(map) + 1);
	tab = ft_alloc(tab, map);
	if (!tab)
		return (0);
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
	return (tab);
}

char	*ft_stradd(char *str, char *to_add)
{
	int		i;
	char	*c;

	i = 0;
	c = (char *)malloc(ft_strlen(str) + 2);
	if (!c)
	{
		free(str);
		return (0);
	}
	while (str[i])
	{
		c[i] = str[i];
		i++;
	}
	free(str);
	c[i++] = to_add[0];
	c[i] = '\0';
	return (c);
}

char	**ber_to_tab(char *c)
{
	int		fd;
	int		ret;
	char	buf[1];
	char	*map;
	char	**tab;

	fd = check_ber(c);
	ret = read(fd, buf, 1);
	if (fd < 1 || ret == -1)
		return (0);
	map = (char *)malloc(1);
	if (!map)
		return (0);
	map[0] = '\0';
	while (ret == 1)
	{
		map = ft_stradd(map, buf);
		if (!map)
			return (0);
		ret = read(fd, buf, 1);
	}
	tab = get_tab(map);
	free(map);
	return (tab);
}
