/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:12:05 by byanis            #+#    #+#             */
/*   Updated: 2023/01/14 17:29:24 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	find_start_exit(char *map_string, t_map *map)
{
	while (map->i < map->num_rows - 1)
	{
		map->j = 0;
		while (map->j < map->num_cols)
		{
			if (map_string[map->i * (map->num_cols + 1) + map->j] == 'P')
			{
				map->start_row = map->i;
				map->start_col = map->j;
			}
			else if (map_string[map->i * (map->num_cols + 1) + map->j] == 'E')
			{
				map->exit_row = map->i;
				map->exit_col = map->j;
			}
			else if (map_string[map->i * (map->num_cols + 1) + map->j] == 'C')
					map->collec_count++;
			map->j++;
		}
		map->i++;
	}
}

/* DFS algorith here :
Checks first the current position if it's not out of boudaries
Then checks if current position is already visited ('V' stands for visited)
Then if current pos is a wall
Then if current pos is a collectible
Checks if all collectibles are collected
It marks the current position as visited and call recursively the function
for respectively North South West and East position
Returns 0 if no valid path were found.*/

int	ft_dfs(char *map_string, t_map *m, int row, int col)
{
	if (row < 0 || row >= m->num_rows || col < 0 || col >= m->num_cols)
		return (0);
	if (map_string[row * (m->num_cols + 1) + col] == 'V')
		return (0);
	if (map_string[row * (m->num_cols + 1) + col] == '1')
		return (0);
	if (map_string[row * (m->num_cols + 1) + col] == 'C')
		m->collec_clctd++;
	if (m->collec_clctd == m->collec_count)
		return (1);
	map_string[row * (m->num_cols + 1) + col] = 'V';
	if (ft_dfs(map_string, m, row - 1, col))
		return (1);
	if (ft_dfs(map_string, m, row + 1, col))
		return (1);
	if (ft_dfs(map_string, m, row, col - 1))
		return (1);
	if (ft_dfs(map_string, m, row, col + 1))
		return (1);
	return (0);
}

int	ft_path_dfs(char *map_string, t_map *map, t_game *game)
{
	find_start_exit(map_string, map);
	game->collec = map->collec_count;
	ft_dfs(map_string, map, map->start_row, map->start_col);
	return (map->collec_clctd == map->collec_count);
}
