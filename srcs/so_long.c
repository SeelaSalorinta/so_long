/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:34:48 by ssalorin          #+#    #+#             */
/*   Updated: 2024/12/30 11:27:10 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_to_null(t_data *data)
{
	data->wall_img = NULL;
	data->player_img = NULL;
	data->collectible_img = NULL;
	data->exit_img = NULL;
	data->empty_img = NULL;
}

static void	load_images(t_data *data)
{
	int	img_width;
	int	img_height;

	set_to_null(data);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &img_width, &img_height);
	if (!data->wall_img)
		exit_game(data, 1);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &img_width, &img_height);
	if (!data->player_img)
		exit_game(data, 1);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/collectible.xpm", &img_width, &img_height);
	if (!data->collectible_img)
		exit_game(data, 1);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &img_width, &img_height);
	if (!data->exit_img)
		exit_game(data, 1);
	data->empty_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/empty.xpm", &img_width, &img_height);
	if (!data->empty_img)
		exit_game(data, 1);
}

static void	initialize_and_create(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * TILE_SIZE,
			data->height * TILE_SIZE, "so_long");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
}

static void	check_if_ber(char *file)
{
	int	i;

	i = (int)ft_strlen(file);
	if (i < 4)
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		exit(1);
	}
	if (file[i - 4] != '.' || file[i - 3] != 'b'
		|| file[i - 2] != 'e' || file[i - 1] != 'r')
	{
		ft_putstr_fd("File is not a .ber file\n", 2);
		exit(1);
	}
}		

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long [file].ber\n", 2);
		return (1);
	}
	check_if_ber(argv[1]);
	data.moves = 0;
	data.map = load_map(argv[1], &data);
	if (check_valid_path(&data) == 1)
	{
		ft_free_map(data.map);
		return (1);
	}
	initialize_and_create(&data);
	load_images(&data);
	if (data.moves == 0)
		ft_printf("Move count: 0\n");
	render_map(&data, 0, 0);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_cross, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
