/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:25:53 by byanis            #+#    #+#             */
/*   Updated: 2023/01/12 16:27:17 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	*map_string;

	if (ac != 2)
		return (0);
	if (!check_ber_format(av[1]))
	{
		ft_printf("Wrong map format. Format should be \"*.ber\"\n");
		return (0);
	}
	map_string = arg_to_str(av[1]);
	if (!parse_map(map_string))
	{
			free(map_string);
			return (0);
	}
	//init_window();
	free(map_string);
}
