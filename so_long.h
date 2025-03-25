/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:04:05 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 11:40:13 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>

# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	void	*empty_img;
	char	**map;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	int		moves;
	int		exit_reachable;
	int		collectible_reachable;
	int		exit_count;
	int		player_count;
	int		collectible_count;
}	t_data;

int		exit_game(t_data *data, int x);
int		validate_map(t_data *data, int width, int heigth);
void	validate_game_objects(t_data *data, char **map);
int		validate_row(t_data *data, char *row, int i, int x);
int		key_hook(int keysym, t_data *data);
int		close_window(t_data *data);
void	ft_free_map(char **map);
int		check_valid_path(t_data *data);
void	render_map(t_data *data, int y, int x);
char	**load_map(char *filename, t_data *data);
int		exit_cross(t_data *data);

#endif
