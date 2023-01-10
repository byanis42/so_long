/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:36:19 by byanis            #+#    #+#             */
/*   Updated: 2023/01/10 19:51:55 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	if (ptr == NULL) {
		return calloc(1, new_size);
	}
	if (new_size == 0) {
		free(ptr);
		return NULL;
	}

	void *new_ptr = ft_calloc(1, new_size);
	if (new_ptr == NULL) {
		return NULL;
	}
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return new_ptr;
}
