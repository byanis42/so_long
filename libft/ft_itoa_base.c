/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:31:16 by byanis            #+#    #+#             */
/*   Updated: 2022/09/20 10:31:16 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(int nbr, int size_base)
{
	int			len;
	long		n;

	n = nbr;
	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n / size_base > 0)
	{
		n = n / size_base;
		len++;
	}
	return (len);
}

static char	*x(long nbr, char *base, int size_base)
{
	char	*itoa;
	int		len;
	int		i;

	len = ft_nbrlen_base((int)nbr, size_base);
	itoa = ft_calloc(len + 1, sizeof(char));
	if (!itoa)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		itoa[i] = '-';
		nbr = nbr * -1;
		i++;
	}
	while (nbr / size_base > 0 && len > i)
	{
		itoa[len - 1] = base[nbr % size_base];
		nbr = nbr / size_base;
		len--;
	}
	itoa[i] = base[nbr % size_base];
	return (itoa);
}

char	*ft_itoa_base(int n, char *base)
{
	long	nbr;
	int		size_base;

	nbr = n;
	if (!base)
		return (NULL);
	size_base = ft_strlen(base);
	return (x(nbr, base, size_base));
}
