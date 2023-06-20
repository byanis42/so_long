/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:10:06 by byanis            #+#    #+#             */
/*   Updated: 2023/01/17 14:47:23 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_image(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image
		(game->mlx_ptr, "images/link.xpm", &game->img.w, &game->img.h);
	game->img.exit = mlx_xpm_file_to_image
		(game->mlx_ptr, "images/zel_w.xpm", &game->img.w, &game->img.h);
	game->img.bckg = mlx_xpm_file_to_image
		(game->mlx_ptr, "images/grass.xpm", &game->img.w, &game->img.h);
	game->img.wall = mlx_xpm_file_to_image
		(game->mlx_ptr, "images/walls.xpm", &game->img.w, &game->img.h);
	game->img.collec = mlx_xpm_file_to_image
		(game->mlx_ptr, "images/ruby.xpm", &game->img.w, &game->img.h);
	if (!game->img.player || !game->img.exit
		|| !game->img.bckg || !game->img.wall || !game->img.collec)
	{
		free_all(game);
		return (0);
	}
	return (1);
}

void	get_win_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map_array[i]) * 32;
	while (game->map_array[i])
		i++;
	game->win_height = i * 32;
}

int	init_window(t_game *game, char *map_string)
{
	game->map_array = ft_split(map_string, '\n');
	if (!game->map_array)
	{
		free(map_string);
		return (0);
	}
	free(map_string);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	get_win_size(game);
	game->mlx_win_ptr = mlx_new_window
		(game->mlx_ptr, game->win_width, game->win_height, "so_long");
	if (!game->mlx_win_ptr)
	{
		free_all(game);
		return (0);
	}
	game->mv_count = 0;
	game->finish = 0;
	load_image(game);
	print_map(game);
	return (1);
}
