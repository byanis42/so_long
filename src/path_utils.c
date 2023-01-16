/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:26 by byanis            #+#    #+#             */
/*   Updated: 2023/01/15 13:48:01 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_td(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
