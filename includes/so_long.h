/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:03:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/17 17:16:59 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Librairies */

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../libft/libftprintf.h"

/* MLX Keys */

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
	int	exit_count;
	int	i;
	int	j;
}	t_map;

typedef struct s_img
{
	void	*bckg;
	void	*wall;
	void	*collec;
	void	*player;
	void	*exit;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	char	**map_array;
	int		win_height;
	int		win_width;
	int		len_map;
	int		mv_count;
	int		collec;
	int		pos_x;
	int		pos_y;
	int		finish;
}	t_game;

/* Functions */

int		check_ber_format(char *str);
char	*arg_to_str(char *input);
void	ft_destroy(t_game *game);
int		init_window(t_game *game, char *map_string);
int		parse_map(char *map_string, t_game *game);
int		is_valid_path(char *map_string, t_game *game);
int		ft_path_dfs(char *map_string, t_map *map, t_game *game);
int		game_init(t_game *game, char *map_string);
int		print_map(t_game *game);
void	player_forward(t_game *game);
void	player_backward(t_game *game);
void	player_right(t_game *game);
void	player_left(t_game *game);

/* utils */

int		get_cols(char *map_string);
int		get_rows(char *map_string);
char	**string_to_td(char *map_parsing, int num_rows, int num_cols);
void	ft_free_td(char **arr);
int		free_all(t_game *game);

#endif
