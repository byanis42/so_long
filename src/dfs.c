/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:12:05 by byanis            #+#    #+#             */
/*   Updated: 2023/01/12 16:25:28 by byanis           ###   ########.fr       */
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

int ft_dfs(char* map, t_map* m, int row, int col)
{
	if (row < 0 || row >= m->num_rows || col < 0 || col >= m->num_cols)
		return (0);
	if (map[row * (m->num_cols + 1) + col] == 'V')
		return (0);
	if (map[row * (m->num_cols + 1) + col] == '1')
		return (0);
	if (map[row * (m->num_cols + 1) + col] == 'C')
		m->collec_clctd++;
	if (m->collec_clctd == m->collec_count)
		return (1);
	map[row * (m->num_cols + 1) + col] = 'V';
	if (ft_dfs(map, m, row - 1, col))
		return (1);
	if (ft_dfs(map, m, row + 1, col))
		return (1);
	if (ft_dfs(map, m, row, col - 1))
		return (1);
	if (ft_dfs(map, m, row, col + 1))
		return (1);
	return (0);
}

int	ft_path_dfs(char *map_string, t_map *map)
{
	find_start_exit(map_string, map);
	get_cols(map_string);
	printf("start row = [%d] /// start col = [%d]\n", map->start_row, map->start_col);
	printf("exit row = [%d]  /// exit col = [%d]\ncollectibles count = [%d]", map->exit_row, map->exit_col, map->collec_count);
	ft_dfs(map_string, map, map->start_row, map->start_col);
	printf("\ncollectibles collected = [%d]\n", map->collec_clctd);
	return (map->collec_clctd == map->collec_count);
}
