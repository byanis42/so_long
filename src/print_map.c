/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:48:08 by byanis            #+#    #+#             */
/*   Updated: 2023/01/14 13:54:00 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx_ptr, game->mlx_win_ptr, image, x * 64, y * 64);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->collec == 0)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.exit);
		game->img.exit = mlx_xpm_file_to_image
			(game->mlx_ptr, "images/zel_rdy.xpm", &game->img.w, &game->img.h);
	}
	img_draw(game, game->img.exit, x, y);
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
				img_draw(game, game->img.wall, x, y);
			else if (game->map_array[y][x] == '0')
				img_draw(game, game->img.bckg, x, y);
			else if (game->map_array[y][x] == 'P')
				player_draw(game, game->img.player, x, y);
			else if (game->map_array[y][x] == 'C')
				img_draw(game, game->img.collec, x, y);
			else if (game->map_array[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
