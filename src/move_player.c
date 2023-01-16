/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:43 by byanis            #+#    #+#             */
/*   Updated: 2023/01/15 13:35:28 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Just actualizing struct with new data when player press directionnal key */

void	player_forward(t_game *game)
{
	if (game->map_array[game->pos_y][game->pos_x] == 'E'
			&& game->collec == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		game->map_array[game->pos_y + 1][game->pos_x] = '0';
		game->mv_count++;
		game->finish = 1;
		print_map(game);
	}
	else if (game->map_array[game->pos_y][game->pos_x] == '1'
			|| game->map_array[game->pos_y][game->pos_x] == 'E')
		game->pos_y += 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		if (game->map_array[game->pos_y][game->pos_x] == 'C')
			game->collec -= 1;
		game->map_array[game->pos_y][game->pos_x] = 'P';
		game->map_array[game->pos_y + 1][game->pos_x] = '0';
		game->mv_count++;
		print_map(game);
	}
}

void	player_backward(t_game *game)
{
	if (game->map_array[game->pos_y][game->pos_x] == 'E'
			&& game->collec == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		game->map_array[game->pos_y - 1][game->pos_x] = '0';
		game->mv_count++;
		game->finish = 1;
		print_map(game);
	}
	else if (game->map_array[game->pos_y][game->pos_x] == '1'
			|| game->map_array[game->pos_y][game->pos_x] == 'E')
		game->pos_y -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		if (game->map_array[game->pos_y][game->pos_x] == 'C')
			game->collec -= 1;
		game->map_array[game->pos_y][game->pos_x] = 'P';
		game->map_array[game->pos_y - 1][game->pos_x] = '0';
		game->mv_count++;
		print_map(game);
	}
}

void	player_right(t_game *game)
{
	if (game->map_array[game->pos_y][game->pos_x] == 'E'
			&& game->collec == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		game->map_array[game->pos_y][game->pos_x - 1] = '0';
		game->mv_count++;
		game->finish = 1;
		print_map(game);
	}
	else if (game->map_array[game->pos_y][game->pos_x] == '1'
			|| game->map_array[game->pos_y][game->pos_x] == 'E')
		game->pos_x -= 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		if (game->map_array[game->pos_y][game->pos_x] == 'C')
			game->collec -= 1;
		game->map_array[game->pos_y][game->pos_x] = 'P';
		game->map_array[game->pos_y][game->pos_x - 1] = '0';
		game->mv_count++;
		print_map(game);
	}
}

void	player_left(t_game *game)
{
	if (game->map_array[game->pos_y][game->pos_x] == 'E'
			&& game->collec == 0)
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		game->map_array[game->pos_y][game->pos_x + 1] = '0';
		game->mv_count++;
		game->finish = 1;
		print_map(game);
	}
	else if (game->map_array[game->pos_y][game->pos_x] == '1'
			|| game->map_array[game->pos_y][game->pos_x] == 'E')
		game->pos_x += 1;
	else
	{
		mlx_clear_window(game->mlx_ptr, game->mlx_win_ptr);
		if (game->map_array[game->pos_y][game->pos_x] == 'C')
			game->collec -= 1;
		game->map_array[game->pos_y][game->pos_x] = 'P';
		game->map_array[game->pos_y][game->pos_x + 1] = '0';
		game->mv_count++;
		print_map(game);
	}
}
