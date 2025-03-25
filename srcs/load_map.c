/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:40:09 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/18 13:08:18 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strdup_nl(const char *s1)
{
	char	*copy;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	len = (int)ft_strlen(s1);
	i = 0;
	if (len > 0 && s1[len - 1] == '\n')
		len--;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

static void	check_line(t_data *data, char **map, int i)
{
	if (data->height < 3 || data->width < 3)
	{
		ft_putstr_fd("Error: Maps height and width must be at least 3\n", 2);
		ft_free_map(map);
		exit(1);
	}
	if (ft_strlen(map[0]) != ft_strlen(map[i]))
	{
		ft_putstr_fd("Error: Inconsistent row length\n", 2);
		ft_free_map(map);
		exit(1);
	}
	if (validate_row(data, map[i], i, 0) == 1)
	{
		ft_free_map(map);
		exit(1);
	}
}

static char	**make_map(t_data *data, int fd, char **map, int i)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup_nl(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (map[0] == NULL)
	{
		ft_putstr_fd("Error: File is empty\n", 2);
		ft_free_map(map);
		exit(1);
	}
	free(line);
	i = (int)ft_strlen(map[0]);
	data->width = i;
	i = 0;
	while (map[i])
		check_line(data, map, i++);
	return (map);
}

static void	count_height(t_data *data, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->height = i;
	close(fd);
}

char	**load_map(char *filename, t_data *data)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Couldn't open file\n", 2);
		exit(1);
	}
	count_height(data, fd, 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Couldn't open file\n", 2);
		exit(1);
	}
	map = malloc(sizeof(char *) * (data->height + 1));
	if (!map)
	{
		close(fd);
		exit(1);
	}
	map = make_map(data, fd, map, 0);
	validate_game_objects(data, map);
	return (map);
}
