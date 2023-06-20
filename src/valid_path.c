/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:00:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/17 18:18:04 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Initialize the struct in able to perform the DFS algorithm */

void	init_map_info(t_map *map, char *map_string)
{
	map->num_rows = get_rows(map_string);
	map->num_cols = get_cols(map_string);
	map->start_row = 0;
	map->start_col = 0;
	map->exit_row = 0;
	map->exit_col = 0;
	map->collec_count = 0;
	map->collec_clctd = 0;
	map->i = 0;
	map->j = 0;
}

int	is_valid_path(char *map_string, t_game *game)
{
	t_map	map;
	int		res;

	init_map_info(&map, map_string);
	res = ft_path_dfs(map_string, &map, game);
	if (res)
		return (1);
	return (0);
}
