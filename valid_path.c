/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:00:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/11 17:16:40 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void printMapArray(char** map_array, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows - 1; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%c", map_array[i][j]);
        }
        printf("\n");
    }
}

void	print_arr(char **map_array)
{
	int	i;
	int	j;

	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			ft_printf(" %c-", map_array[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
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
	t_map map;
	char **map_array;

	init_map_info(&map, map_string);
	map_array = string_to_td(map_string, get_rows(map_string), get_cols(map_string));
	printMapArray(map_array, get_rows(map_string), get_cols(map_string));
	//print_arr(map_array);
	ft_free_td(map_array, get_rows(map_string));
	printf("\n\nresult_path = %d\n\n", valid_pathing(map_string, &map));
	return (1);
}
