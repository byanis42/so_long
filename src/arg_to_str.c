/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:34:54 by byanis            #+#    #+#             */
/*   Updated: 2023/01/15 02:44:56 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

/* Reads the map and put it in a string */

static char	*ft_ret_null_free(char *result)
{
	if (!result)
		return (NULL);
	free(result);
	return (NULL);
}

int	check_if_directory(int fd)
{
	char	buffer[1];
	ssize_t	n;

	n = read(fd, buffer, 1);
	if (n < 0)
	{
		ft_printf("Error\n");
		perror("Read error");
		exit(1);
	}
	if (n == 0)
		return (1);
	else
		return (0);
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
		if (bytes_read)
			result = ft_realloc(result, result_size + bytes_read + 1);
		if (!result)
			return (ft_ret_null_free(result));
		ft_memcpy(result + result_size, buffer, bytes_read);
		result_size += bytes_read;
	}
	if (bytes_read == -1)
		return (ft_ret_null_free(result));
	close(fd);
	result = ft_realloc(result, result_size + 1);
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
		perror("Error\n");
		return (NULL);
	}
	if (!check_if_directory(fd))
		return (NULL);
	return (a_t_s(result, fd));
}
