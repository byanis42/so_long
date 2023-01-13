/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:25:53 by byanis            #+#    #+#             */
/*   Updated: 2023/01/14 00:44:32 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	*map_string;
	t_game	game;

	if (ac == 2)
	{
		if (!check_ber_format(av[1]))
		{
			ft_printf("Error\n==>Wrong map extension. Map ext : \"*.ber\"\n");
			return (1);
		}
		map_string = arg_to_str(av[1]);
		if (!map_string)
			return (0);
		if (!parse_map(map_string))
		{
			free(map_string);
			return (1);
		}
		game_init(&game, arg_to_str(av[1]));
		free(map_string);
		free_all(&game);
		printf("test2\n");
	}
	else
		ft_printf("Error\n==> Wrong number of parameters \n");
}
