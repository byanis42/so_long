/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:03:29 by byanis            #+#    #+#             */
/*   Updated: 2023/01/14 00:36:48 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_all(game);
	// else if (!game->endgame)
	// {
	// 	game_events(keycode, game);
	// 	//printf("Moves: %d\n", game->moves);
	// }
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}


int	game_init(t_game *game, char *map_string)
{
	init_window(game, map_string);
	// mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	// mlx_key_hook(game->mlx_win_ptr, &handle_input, game);
	mlx_hook(game->mlx_win_ptr, 2, 1L << 0, keypress, game);
	printf("test\n");
	mlx_loop(game->mlx_ptr);
		return (1);
}
