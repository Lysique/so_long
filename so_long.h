/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:21:11 by tamighi           #+#    #+#             */
/*   Updated: 2021/10/13 09:56:55 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img {
	void			*img;
	int				w;
	int				h;
}				t_img;

typedef struct s_pos {
	int	i;
	int	j;
}				t_pos;

typedef struct s_ennemyInstance {
	int		side;
	int		sprite_loop;
	t_pos	pos;
	t_pos	to;
}				t_ennemyInstance;

typedef struct s_utils {
	t_img				**sprites;
	char				**map;
	t_mlx				*mlx;
	t_ennemyInstance	*ennemy;
	int					frame_loop;
	int					sprite_loop;
	int					statut;
	int					ennemy_statut;
	int					step;
	int					side;
	t_pos				pos;
	t_pos				to;
}				t_utils;

int					ft_strlen(char *c);
int					map_length(char **map, char axis);
t_pos				get_element_pos(char **map, char element);
void				string_to_window(t_utils *utils, char *string);
int					ennemy_side_update(t_ennemyInstance ennemy);

int					check_ber(char *c);
char				**ber_to_tab(char *c);
int					check_map(char **map);

char				**free_my_tab(char **tab);
int					free_my_struct(t_img *img);
t_img				**free_my_sprites(t_img **sprites, t_mlx *mlx, int x);
void				free_my_utils(t_utils *utils);

t_img				*img_init(t_mlx *mlx, char *object, int n);
t_img				**imgs_tab(t_mlx *mlx);

t_utils				create_utils(char **map, t_mlx *mlx, t_img **sprites);
void				put_walls(t_pos pos, t_mlx *mlx, t_img *img, char **map);
t_ennemyInstance	*create_ennemy_instance(char **map);
void				ennemy_idle(t_utils *utils);
void				ennemy_run(t_utils *utils);
int					number_of_ennemies(char **map);
void				display_map(t_utils *utils);
void				put_bg(t_pos pos, t_utils *utils);
int					characters_loop(t_utils *utils);
void				put_nb_step(int step, t_utils *utils);
void				enypos(t_utils *utils, t_ennemyInstance eny, t_img *imgs);
int					key_hook(int key, void *arg);
void				update_player_pose(t_utils *utils, t_img *sprites);
int					detect_player(t_utils *utils, t_ennemyInstance ennemy);
void				key_update(t_utils *utils);

void				game_over(t_utils *utils);
void				end_time_out(t_utils *utils);
void				victory_end(t_utils *utils);
void				close_game(t_utils *utils);
int					mouse_press(int keycode, t_utils *utils);

#endif
