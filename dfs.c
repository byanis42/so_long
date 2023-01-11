/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:12:05 by byanis            #+#    #+#             */
/*   Updated: 2023/01/11 17:54:16 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	find_start_exit(char *map_string, t_map *map)
{
	while (map->i < map->num_rows)
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

// void findStartAndExit(char* map, int num_rows, int num_cols, int* start_row, int* start_col, int* exit_row, int* exit_col, int* collectibles_count) {
//     for (int i = 0; i < num_rows; i++) {
//         for (int j = 0; j < num_cols; j++) {
//             if (map[i*(num_cols+1) + j] == 'P') {
//                 *start_row = i;
//                 *start_col = j;
//             } else if (map[i*(num_cols+1) + j] == 'E') {
//                 *exit_row = i;
//                 *exit_col = j;
//             } else if (map[i*(num_cols+1) + j] == 'C') {
//                 (*collectibles_count)++;
//             }
//         }
//     }
// }

int ft_dfs(char* map, t_map* m, int row, int col) {
    if (row < 0 || row >= m->num_rows || col < 0 || col >= m->num_cols) {
        return 0;
    }
    if (map[row*(m->num_cols+1) + col] == 'V') {
        return 0;
    }
    if (map[row*(m->num_cols+1) + col] == '1') {
        return 0;
    }
	printf("===========\n");
    if (map[row*(m->num_cols+1) + col] == 'C') {
        m->collec_clctd++;
    }
    if(m->collec_clctd == m->collec_count){
		printf("YYYYY\n");
		return 1;
	}
    map[row*(m->num_cols+1) + col] = 'V';
    if(ft_dfs(map, m, row-1, col))
	{
		printf("ZZZZ\n");
		return 1; // North
	}
    if(ft_dfs(map, m, row+1, col))
	{
	printf("XXXX\n");
		return 1; // South
	}
    if(ft_dfs(map, m, row, col-1)) return 1; // West
    if(ft_dfs(map, m, row, col+1)) return 1; // East
    return 0;
}
// static void	ft_dfs(char *map_string, t_map *map, int start_row, int start_col)
// {
// 	if (start_row < 0 || start_row >= map->num_rows ||
// 			map->start_col < 0 || start_col >= map->num_cols)
// 		return;
// 	if (map_string[start_row * (map->num_cols + 1) + start_col] == 'V')
// 		return;
// 	if (map_string[start_row * (map->num_cols + 1) + start_col] == '1')
// 		return;
// 	if (map_string[start_row * (map->num_cols + 1) + start_col] == 'C')
// 		{
// 			map->collec_clctd++;
// 			printf(">> CLCTD = [%d\n]", map->collec_clctd);
// 		}
// 	map_string[start_row * (map->num_cols + 1) + start_col] = 'V';
// 	ft_dfs(map_string, map, start_row - 1, start_col);
// 	ft_dfs(map_string, map, start_row + 1, start_col);
// 	ft_dfs(map_string, map, start_row, start_col - 1);
// 	ft_dfs(map_string, map, start_row, start_col + 1);
// }

// void dfs(char* map, int num_rows, int num_cols, int start_row, int start_col, int* collectibles_collected, int exit_row, int exit_col) {
// 	if (start_row < 0 || start_row >= num_rows || start_col < 0 || start_col >= num_cols)
// 		return;
// 	if (map[start_row*(num_cols+1) + start_col] == 'V')
// 		return;
// 	if (map[start_row*(num_cols+1) + start_col] == '1')
// 		return;
// 	if (map[start_row*(num_cols+1) + start_col] == 'C')
// 		(collectibles_collected)++;

// 	map[row(num_cols+1) + col] = 'V';
// 	dfs(map, num_rows, num_cols, start_row-1, start_col, collectibles_collected, exit_row, exit_col); // North
// 	dfs(map, num_rows, num_cols, start_row+1, start_col, collectibles_collected, exit_row, exit_col); // South
// 	dfs(map, num_rows, num_cols, start_row, start_col-1, collectibles_collected, exit_row, exit_col); // West
// 	dfs(map, num_rows, num_cols, start_row, start_col+1, collectibles_collected, exit_row, exit_col); // East
// }


int	valid_pathing(char *map_string, t_map *map)
{
	int	start_row;
	int	start_col;

	start_row = map->start_row;
	start_col = map->start_col;
	find_start_exit(map_string, map);
	printf("start row = [%d] /// start col = [%d]\n", map->start_row, map->start_col);
	printf("exit row = [%d]  /// exit col = [%d]\ncollec count = [%d]", map->exit_row, map->exit_col, map->collec_count);
	ft_dfs(map_string, map, start_row, start_col);
	if (map_string[map->exit_row * (map->num_cols + 1) + map->exit_col] == 'V' &&
		map->collec_clctd == map->collec_count)
		return (1);
	return (0);

}

// bool isValidPath(char* map, int num_rows, int num_cols)
// {
// 	int start_row, start_col, exit_row, exit_col, collectibles_count = 0;
// 	findStartAndExit(map, num_rows, num_cols, &start_row, &start_col, &exit_row, &exit_col, &collectibles_count);
// 	int collectibles_collected = 0;
// 	dfs(map, num_rows, num_cols, start_row, start_col, &collectibles_collected, exit_row, exit_col);
// 	if (map[exit_row*(num_cols+1) + exit_col] == 'V' && collectibles_collected == collectibles_count) {
// 	return true;
// 	}
// 	return false;
// }
