/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:00:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/12 15:13:09 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_arr(char **map_array, int num_rows, int num_cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_rows - 1)
	{
		j = 0;
		while (j < num_cols)
		{
			ft_printf("%c", map_array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

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

int	is_valid_path(char *map_string)
{
	t_map	map;
	int		res;

	init_map_info(&map, map_string);
	res = ft_path_dfs(map_string, &map);
	printf("\nresult valid path = [%d]\n", res);
	if (res)
		return (1);
	return (0);
}
