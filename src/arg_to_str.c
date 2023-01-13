/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:54 by byanis            #+#    #+#             */
/*   Updated: 2023/01/13 22:42:13 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

/* Reads the map and put it in a string */

static char	*ft_ret_null_free(char *result)
{
	if (result)
		free(result);
	return (NULL);
}

char	*a_t_s(char *result, int fd)
{
	char	buffer[4096];
	size_t	result_size;
	ssize_t	bytes_read;

	result_size = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof buffer);
		result = realloc(result, result_size + bytes_read + 1);
		if (!result)
			return (ft_ret_null_free(result));
		ft_memcpy(result + result_size, buffer, bytes_read);
		result_size += bytes_read;
	}
	if (bytes_read == -1)
		ft_ret_null_free(result);
	close(fd);
	result = realloc(result, result_size + 1);
	result[result_size] = '\0';
	return (result);
}

char	*arg_to_str(char *input)
{
	char	*result;
	int		fd;

	result = NULL;
	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile missing !\n");
		return (NULL);
	}
	else
		return (a_t_s(result, fd));
}
