/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:38:28 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/17 13:27:56 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **original_map, int height, int i)
{
	char	**new_map;

	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	while (i < height)
	{
		new_map[i] = ft_strdup(original_map[i]);
		if (!new_map[i])
		{
			ft_free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[height] = NULL;
	return (new_map);
}

static int	check_if_reachable(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->width || y >= data->height)
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (1);
	if (map[y][x] == 'C')
		data->collectible_reachable++;
	if (map[y][x] == 'E')
		data->exit_reachable = 1;
	map[y][x] = 'V';
	check_if_reachable(map, x + 1, y, data);
	check_if_reachable(map, x - 1, y, data);
	check_if_reachable(map, x, y + 1, data);
	check_if_reachable(map, x, y - 1, data);
	return (0);
}

int	check_valid_path(t_data *data)
{
	char	**temp_map;

	temp_map = copy_map(data->map, data->height, 0);
	if (!temp_map)
		return (1);
	data->collectible_reachable = 0;
	data->exit_reachable = 0;
	check_if_reachable(temp_map, data->player_x, data->player_y, data);
	ft_free_map(temp_map);
	if (data->collectible_reachable != data->collectible_count
		|| data->exit_reachable != 1)
	{
		if (data->collectible_reachable != data->collectible_count)
			ft_putstr_fd("Error: Not all collectibles are reachable\n", 2);
		if (data->exit_reachable != 1)
			ft_putstr_fd("Error: Exit is not reachable\n", 2);
		return (1);
	}
	return (0);
}
