/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:48:08 by byanis            #+#    #+#             */
/*   Updated: 2023/01/18 11:33:02 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx_ptr, game->mlx_win_ptr, image, x * 32, y * 32);
}

void	print_player(t_game *game, void *image, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
	print_image(game, image, x, y);
}

void	print_exit(t_game *game, int x, int y)
{
	if (game->collec == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.exit);
		game->img.exit = mlx_xpm_file_to_image
			(game->mlx_ptr, "images/zel_rdy.xpm", &game->img.w, &game->img.h);
	}
	print_image(game, game->img.exit, x, y);
}

int	print_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_array[y])
	{
		x = 0;
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == '1')
				print_image(game, game->img.wall, x, y);
			else if (game->map_array[y][x] == '0')
				print_image(game, game->img.bckg, x, y);
			else if (game->map_array[y][x] == 'P')
				print_player(game, game->img.player, x, y);
			else if (game->map_array[y][x] == 'C')
				print_image(game, game->img.collec, x, y);
			else if (game->map_array[y][x] == 'E')
				print_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
