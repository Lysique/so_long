/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ennemy_instance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:36:36 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/31 14:28:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ennemy	ennemy_deploy(int i, int j, int *count)
{
	t_ennemy	new_ennemy;

	new_ennemy.pos.i = i;
	new_ennemy.pos.j = j;
	new_ennemy.to = new_ennemy.pos;
	new_ennemy.side = (i + *count) % 2;
	new_ennemy.sprite_loop = 0;
	(*count)++;
	return (new_ennemy);
}

int	number_of_ennemies(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'I')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

t_ennemy	*create_ennemy_instance(char **map)
{
	int			i;
	int			j;
	t_ennemy	*ennemy;
	int			count;

	i = 0;
	j = 0;
	ennemy = malloc(sizeof(t_ennemy) * number_of_ennemies(map) + 1);
	if (!ennemy)
		return (0);
	count = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'I')
				ennemy[count] = ennemy_deploy(i, j, &count);
			i++;
		}
		i = 0;
		j++;
	}
	return (ennemy);
}
