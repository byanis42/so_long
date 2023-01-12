/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:26 by byanis            #+#    #+#             */
/*   Updated: 2023/01/12 15:13:04 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_free_td(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**fill_array(char **map_array, char *map_string)
{
	int	i;
	int	curr_col;
	int	curr_row;

	i = -1;
	curr_col = 0;
	curr_row = 0;
	while (map_string[++i])
	{
		if (map_string[i] != '\n')
		{
			map_array[curr_row][curr_col] = map_string[i];
			curr_col++;
		}
		else
		{
			curr_row++;
			curr_col = 0;
		}
	}
	return (map_array);
}

char	**string_to_td(char *map_string, int num_rows, int num_cols)
{
	int		i;
	char	**map_array;

	i = 0;
	map_array = malloc(num_rows * sizeof(char *));
	if (!map_array)
		return (NULL);
	while (i < num_rows)
	{
		map_array[i] = malloc(num_cols * sizeof(char));
		if (!map_array[i])
			return (ft_free_td(map_array, i));
		i++;
	}
	fill_array(map_array, map_string);
	return (map_array);
}

int	get_rows(char *map_string)
{
	int	len;
	int	num_rows;
	int	i;

	i = -1;
	num_rows = 1;
	len = ft_strlen(map_string);
	while (++i < len)
	{
		if (map_string[i] == '\n')
			num_rows++;
	}
	return (num_rows);
}

int	get_cols(char *map_string)
{
	int	len;
	int	num_cols;
	int	curr_col;
	int	i;

	len = ft_strlen(map_string);
	num_cols = 0;
	curr_col = 0;
	i = -1;
	while (++i < len)
	{
		if (map_string[i] == '\n')
		{
			if (curr_col > num_cols)
				num_cols = curr_col;
			curr_col = 0;
		}
		else
			curr_col++;
	}
	if (curr_col > num_cols)
		num_cols = curr_col;
	return (num_cols);
}
