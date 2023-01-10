/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:03:15 by byanis            #+#    #+#             */
/*   Updated: 2023/01/10 18:28:17 by byanis           ###   ########.fr       */
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

/* Struct */

typedef struct s_game
{
	void	*mlx_ptr;
}	t_game;

/* Functions */

int		check_ber_format(const char *str);
char	*arg_to_str(char *input);
void	ft_destroy(void *mlx_ptr, void *win_ptr);
void	init_window(void);
int		parse_map(const char *map_string);

#endif
