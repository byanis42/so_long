/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:03:29 by byanis            #+#    #+#             */
/*   Updated: 2023/01/16 17:29:18 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Initialize window and events with appropriate mask
	see the X.h documentation for details about events and masks*/

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
		ft_printf("Move count: %d\n", game->mv_count);
		ft_printf("Collectibles left %d\n", game->collec);
	}
	return (0);
}

int	game_init(t_game *game, char *map_string)
{
	if (init_window(game, map_string))
	{
		mlx_hook
		(game->mlx_win_ptr, KeyPress, KeyPressMask, keypress, game);
		mlx_hook
		(game->mlx_win_ptr, DestroyNotify, StructureNotifyMask, free_all, game);
		mlx_hook
		(game->mlx_win_ptr, FocusIn, FocusChangeMask, print_map, game);
		mlx_loop(game->mlx_ptr);
		return (1);
	}
	return (0);
}
