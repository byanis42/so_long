/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_free_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:13:57 by byanis            #+#    #+#             */
/*   Updated: 2023/01/16 17:21:17 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_images(t_game *game)
{
	if (game->img.player)
		mlx_destroy_image(game->mlx_ptr, game->img.player);
	if (game->img.exit)
		mlx_destroy_image(game->mlx_ptr, game->img.exit);
	if (game->img.bckg)
		mlx_destroy_image(game->mlx_ptr, game->img.bckg);
	if (game->img.wall)
		mlx_destroy_image(game->mlx_ptr, game->img.wall);
	if (game->img.collec)
		mlx_destroy_image(game->mlx_ptr, game->img.collec);
}

void	ft_destroy(t_game *game)
{
	if (game->mlx_win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
}

int	free_all(t_game *game)
{
	if (game->map_array)
		ft_free_td(game->map_array);
	ft_destroy_images(game);
	ft_destroy(game);
	exit (0);
	return (0);
}
