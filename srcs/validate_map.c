/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:59 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/17 14:31:42 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_game_objects(t_data *data, char **map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				data->player_count++;
			}
			if (map[y][x] == 'C')
				data->collectible_count++;
			if (map[y][x] == 'E')
				data->exit_count++;
			x++;
		}
		y++;
	}
}

void	validate_game_objects(t_data *data, char **map)
{
	if (data->height > 32 || data->width > 64)
	{
		ft_free_map(map);
		ft_putstr_fd("Error: Map must be max 32x64\n", 2);
		exit(1);
	}
	data->exit_count = 0;
	data->collectible_count = 0;
	data->player_count = 0;
	count_game_objects(data, map);
	if (data->player_count != 1)
		ft_putstr_fd("Error: Map must contain exactly one player\n", 2);
	if (data->collectible_count == 0)
		ft_putstr_fd("Error: Map must contain at least one collectible\n", 2);
	if (data->exit_count != 1)
		ft_putstr_fd("Error: Map must contain exactly one exit\n", 2);
	if (data->player_count != 1 || data->exit_count != 1
		|| data->collectible_count == 0)
	{
		ft_free_map(map);
		exit(1);
	}
}

static int	check_walls(t_data *data, char *row, int i, int x)
{
	if (row[x] != '1')
	{
		if (i == 0)
		{
			ft_putstr_fd("Error: Top row not fully walled\n", 2);
			return (1);
		}
		else if (i == data->height - 1)
		{
			ft_putstr_fd("Error: Bottom row not fully walled\n", 2);
			return (1);
		}
		else if (i > 0 && i < data->height - 1 && x == 0)
		{
			ft_putstr_fd("Error: Left column not fully walled\n", 2);
			return (1);
		}
		else if (i > 0 && i < data->height - 1 && x == (int)ft_strlen(row) - 1)
		{
			ft_putstr_fd("Error: Right column not fully walled\n", 2);
			return (1);
		}
	}
	return (0);
}

int	validate_row(t_data *data, char *row, int i, int x)
{
	while (row[x])
	{
		if (check_walls(data, row, i, x) == 1)
			return (1);
		if (row[x] != '1' && row[x] != '0' && row[x] != 'P'
			&& row[x] != 'C' && row[x] != 'E')
		{
			ft_putstr_fd("Error: Invalid character\n", 2);
			return (1);
		}
		x++;
	}
	return (0);
}
