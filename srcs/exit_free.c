/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:42:44 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 11:04:40 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	exit_cross(t_data *data)
{
	exit_game(data, 0);
	return (0);
}	

int	exit_game(t_data *data, int x)
{
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
	if (data->collectible_img)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
	if (data->empty_img)
		mlx_destroy_image(data->mlx_ptr, data->empty_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free_map(data->map);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(x);
	return (0);
}
