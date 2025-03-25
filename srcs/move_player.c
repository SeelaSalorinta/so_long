/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:24:50 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/18 11:31:35 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *data, int new_x, int new_y)
{
	if (data->moves == 2147483647)
		exit_game(data, 1);
	if (data->map[data->player_y][data->player_x] != 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty_img,
			data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img,
			data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	data->moves++;
	ft_printf("Move count: %d\n", data->moves);
	data->player_x = new_x;
	data->player_y = new_y;
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->collectible_count--;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	if (data->map[data->player_y][data->player_x] == 'E'
		&& data->collectible_count == 0)
		exit_game(data, 0);
}

int	key_hook(int keycode, t_data *data)
{
	int		new_x;
	int		new_y;
	int		curr_x;
	int		curr_y;

	curr_x = data->player_x;
	curr_y = data->player_y;
	new_x = curr_x + ((keycode == KEY_D) - (keycode == KEY_A));
	new_y = curr_y + ((keycode == KEY_S) - (keycode == KEY_W));
	if (keycode == KEY_ESC)
		exit_game(data, 0);
	if (new_x >= 0 && new_x < data->width && new_y >= 0 && new_y < data->height
		&& data->map[new_y][new_x] != '1')
	{
		if (keycode == KEY_D || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_W)
			move_player(data, new_x, new_y);
	}
	return (0);
}
