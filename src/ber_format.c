/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:47:23 by byanis            #+#    #+#             */
/*   Updated: 2023/01/15 13:37:51 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if input map format is .ber */

int	check_ber_format(char *str)
{
	int	length;
	int	i;

	length = ft_strlen(str);
	if (length < 5)
		return (0);
	i = length - 4;
	if (str[i++] != '.')
		return (0);
	if (str[i++] != 'b')
		return (0);
	if (str[i++] != 'e')
		return (0);
	if (str[i++] != 'r')
		return (0);
	return (1);
}
