/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:03:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/11 17:16:53 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Librairies */

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../libft/libftprintf.h"

/* Defines */

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 700

# define M_EMPTY '0'
# define M_WALL '1'
# define M_COLLECT 'C'
# define M_EXIT 'E'
# define M_START 'P'

/* Structs */

typedef struct s_map
{
	int	num_rows;
	int	num_cols;
	int	start_row;
	int	start_col;
	int	exit_row;
	int	exit_col;
	int	collec_count;
	int	collec_clctd;
	int	i;
	int	j;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
}	t_game;

/* Functions */

int		check_ber_format(char *str);
char	*arg_to_str(char *input);
void	ft_destroy(void *mlx_ptr, void *win_ptr);
void	init_window(void);
int		parse_map(char *map_string);
int		is_valid_path(char *map_string);
int		valid_pathing(char *map_string, t_map *map);

/* utils */

int		get_cols(char *map_string);
int		get_rows(char *map_string);
char	**string_to_td(char *map_parsing, int num_rows, int num_cols);
char	**ft_free_td(char **arr, int len);

#endif
