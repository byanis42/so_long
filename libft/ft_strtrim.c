/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:38:06 by byanis            #+#    #+#             */
/*   Updated: 2022/09/20 10:38:06 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_isset(s1[i], set))
		i++;
	if (i == len)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (ft_isset(s1[j], set))
		j--;
	ptr = ft_substr(s1, i, j - i + 1);
	return (ptr);
}
