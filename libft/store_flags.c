/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byanis <byanis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:28:23 by byanis            #+#    #+#             */
/*   Updated: 2023/01/02 16:48:04 by byanis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static int	get_number(const char *format, int *index)
{
	int	type_flag;

	type_flag = 0;
	while (ft_isdigit(format[*index]))
	{
		type_flag = type_flag * 10 + format[*index] - '0';
		(*index)++;
	}
	return (type_flag);
}

static void	store_zero_minus(const char *format, t_flags *flags)
{
	while (format[flags->index] == '-' || format[flags->index] == '0')
	{
		if (format[flags->index] == '-')
			flags->minus = 1;
		if (format[flags->index] == '0' && !flags->minus)
			flags->zero = 1;
		else
			flags->zero = 0;
		flags->index++;
	}
}

static void	store_width(const char *format, va_list ap, t_flags *flags)
{
	if (format[flags->index] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->zero = 0;
			flags->width *= -1;
		}
		flags->index++;
	}
	else
		flags->width = get_number(format, &flags->index);
}

static void	store_precision(const char *format, va_list ap, t_flags *flags)
{
	flags->dot = 1;
	flags->index++;
	if (format[flags->index] == '*')
	{
		flags->precision = va_arg(ap, int);
		if (flags->precision >= 0)
			flags->zero = 0;
		flags->index++;
	}
	else
	{
		if (ft_isdigit(format[flags->index]))
			flags->zero = 0;
		flags->precision = get_number(format, &flags->index);
	}
}

void	store_flags(const char *format, va_list ap, t_flags *flags)
{
	flags->index++;
	if (format[flags->index] == '-' || format[flags->index] == '0')
		store_zero_minus(format, flags);
	store_width(format, ap, flags);
	if (format[flags->index] == '.')
		store_precision(format, ap, flags);
}
