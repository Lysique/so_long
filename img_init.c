/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:48:29 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/12 10:52:48 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2, int x)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 3);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (x)
		free(s1);
	return (str);
}

char	*ft_file_name(char *object, int x)
{
	char	*str;
	int		length;
	int		i;

	length = 1;
	str = ft_strjoin("./png", object, 0);
	str = ft_strjoin(str, object, 1);
	i = ft_strlen(str);
	while (x / length >= 10)
		length = length * 10;
	while (length != 0)
	{
		str[i] = x / length + '0';
		x = x % length;
		length = length / 10;
		i++;
	}
	str[i] = '\0';
	str = ft_strjoin(str, ".xpm", 1);
	return (str);
}

char	**get_img_names(char *object, int n)
{
	char	**img_tab;
	int		i;

	img_tab = (char **)malloc(sizeof(char *) * (n + 1));
	if (!img_tab)
		return (0);
	i = 0;
	while (n > i)
	{
		img_tab[i] = ft_file_name(object, i);
		if (!img_tab[i])
			return (free_my_tab(img_tab));
		i++;
	}
	img_tab[i] = 0;
	return (img_tab);
}

t_img	do_img(char *file, t_mlx *mlx)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, file, &img.w, &img.h);
	return (img);
}

t_img	*img_init(t_mlx *mlx, char *object, int nImg)
{
	t_img	*sprites;
	char	**file_tab;
	int		i;

	i = 0;
	file_tab = get_img_names(object, nImg);
	if (!file_tab)
		return (0);
	sprites = (t_img *)malloc(sizeof(t_img) * nImg + 1);
	if (!sprites)
		return ((t_img *)*free_my_tab(file_tab));
	while (i < nImg)
	{
		sprites[i] = do_img(file_tab[i], mlx);
		i++;
	}
	sprites[i].img = 0;
	free_my_tab(file_tab);
	return (sprites);
}
