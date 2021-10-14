/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nb_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:13 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 08:23:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *string)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(ft_strlen(string) + 10);
	while (string[i])
	{
		new[i] = string[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*step_to_string(int nb)
{
	char	*steps;
	int		length;
	int		i;
	int		len;

	steps = ft_strdup("Steps : ");
	length = 1;
	i = 0;
	len = ft_strlen(steps);
	while (nb / length >= 10)
		length = length * 10;
	while (length != 0)
	{
		steps[len + i] = nb / length + '0';
		nb = nb % length;
		length = length / 10;
		i++;
	}
	steps[len + i] = '\0';
	return (steps);
}

void	put_nb_step(int step, t_utils *utils)
{
	char	*string;
	t_pos	pos;
	int		color;

	color = 0X000000FF;
	string = step_to_string(step);
	pos.i = 0;
	pos.j = 0;
	put_bg(pos, utils);
	put_walls(pos, utils->mlx, utils->sprites[1], utils->map);
	pos.i += 1;
	put_bg(pos, utils);
	put_walls(pos, utils->mlx, utils->sprites[1], utils->map);
	mlx_string_put(utils->mlx->mlx, utils->mlx->win, 10, 10, color, string);
	free(string);
}
