/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:18:42 by byanis            #+#    #+#             */
/*   Updated: 2023/01/10 18:26:00 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	map_is_rectangle(const char *map_string)
{
	int	row_length;
	int	col_length;
	int	i;
	int	current_col_length;

	i = 0;
	col_length = 0;
	row_length = 0;
	while (map_string[i] != '\0')
	{
		current_col_length = 0;
		while (map_string[i] != '\n' && map_string[i++] != '\0')
			current_col_length++;
		if (col_length == 0)
			col_length = current_col_length;
		else if (col_length != current_col_length)
			return (0);
		row_length++;
		i++;
	}
	if (map_string[i - 1] != '\n')
		return (0);
	return (1);
}

int	map_is_closed(const char *map_string)
{
	int	col_length;
	int	i;
	int	row_length;

	col_length = 0;
	i = 0;
	while (map_string[i] != '\n' && map_string[i] != '\0')
	{
		if (map_string[i] != '1')
			return (0);
		col_length++;
		i++;
	}
	i++;
	row_length = 1;
	while (map_string[i] != '\0')
	{
		if (map_string[i] != '1' && map_string[i + col_length] != '1')
			return (0);
		i += col_length + 1;
		row_length++;
	}
	return (1);
}

int	map_valid(const char *map_string)
{
	int	exits;
	int	collectibles;
	int	starting_points;
	int	i;

	exits = 0;
	collectibles = 0;
	starting_points = 0;
	i = 0;
	while (map_string[i] != '\0')
	{
		if (map_string[i] == 'E')
			exits++;
		else if (map_string[i] == 'C')
			collectibles++;
		else if (map_string[i] == 'P')
			starting_points++;
	i++;
	}
	if (exits == 1 && collectibles >= 1 && starting_points == 1)
		return (1);
	return (0);
}

int	parse_map(const char *map_string)
{
	//const char	*map = "1111111111111\n10010000000C1\n1000011111001\n1P0011E000001\n1111111111111\n";

	//map_is_rectangle(map_string);
	//map_is_closed(map_string);
	//printf("is rectangle = %d\nis surrounded by walls = %d\nis valid = %d\n", map_is_rectangle(map), map_is_closed(map), map_valid(map));
	printf("is rectangle = %d\nis surrounded by walls = %d\nis valid = %d\n", map_is_rectangle(map_string), map_is_closed(map_string), map_valid(map_string));
	return (1);
}
