/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:58:50 by ysarac            #+#    #+#             */
/*   Updated: 2023/11/03 18:03:31 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_putstr(char *str, int i)
{
	if (!str)
		str = "(null)";
	while (str[i])
	{
		i += write(1, &str[i], 1);
	}
	return (i);
}

int	put_digit(long long int number, char *base, int bsize)
{
	int	counter;
	int	tmp;

	counter = 0;
	if (number < 0 && bsize == 10)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		number *= -1;
		counter++;
	}
	if (number >= bsize)
	{
		tmp = put_digit(number / bsize, base, bsize);
		if (tmp < 0)
			return (-1);
		counter += tmp;
	}
	if (write(1, &base[number % bsize], 1) < 0)
		return (-1);
	return (counter + 1);
}

int	put_digit_pointer(unsigned long int number, char *base, int bsize)
{
	int	counter;
	int	tmp;

	counter = 0;
	if (number < 0 && bsize == 10)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		number *= -1;
		counter++;
	}
	if (number >= (unsigned long int)bsize)
	{
		tmp = put_digit(number / bsize, base, bsize);
		if (tmp < 0)
			return (-1);
		counter += tmp;
	}
	if (write(1, &base[number % bsize], 1) < 0)
		return (-1);
	return (counter + 1);
}

static int	ft_formats(va_list args, const char formats)
{
	if (formats == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	else if (formats == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	else if (formats == 'p')
	{
		if (ft_putstr("0x", 0) < 0)
			return (-1);
		return (2 + put_digit_pointer(va_arg(args, unsigned long int),
				"0123456789abcdef", 16));
	}
	else if (formats == 'd' || formats == 'i')
		return (put_digit(va_arg(args, int), "0123456789", 10));
	else if (formats == 'u')
		return (put_digit(va_arg(args, unsigned int), "0123456789", 10));
	else if (formats == 'x')
		return (put_digit(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (formats == 'X')
		return (put_digit(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (formats == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_formats(args, *format);
		}
		else
		{
			len += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (len);
}
