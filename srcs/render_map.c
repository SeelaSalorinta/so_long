/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:04:49 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 11:05:14 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_data *data, int y, int x)
{
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->exit_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->empty_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
}
