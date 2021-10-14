/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:52:06 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 10:17:05 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
