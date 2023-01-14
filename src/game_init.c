/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:03:29 by byanis            #+#    #+#             */
/*   Updated: 2023/01/14 17:15:24 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	handle_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->pos_y--;
		player_forward(game);
	}
	else if (keycode == KEY_S)
	{
		game->pos_y++;
		player_backward(game);
	}
	else if (keycode == KEY_D)
	{
		game->pos_x++;
		player_right(game);
	}
	else if (keycode == KEY_A)
	{
		game->pos_x--;
		player_left(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_all(game);
	else if (!game->finish)
	{
		handle_events(keycode, game);
		ft_printf("Moves: %d\n", game->mv_count);
		ft_printf("Collec left %d\n", game->collec);
	}
	return (0);
}

// int	handle_no_event(void *data)
// {
// 	(void)data;
// 	/* This function needs to exist, but it is useless for the moment */
// 	return (0);
// }

int	game_init(t_game *game, char *map_string)
{
	init_window(game, map_string);

	mlx_hook(game->mlx_win_ptr, 2, 1L << 0, keypress, game);
	mlx_hook(game->mlx_win_ptr, 17, 1L << 17, free_all, game);
	mlx_hook(game->mlx_win_ptr, 9, 1L << 21, print_map, game);

	mlx_loop(game->mlx_ptr);
	return (1);
}
