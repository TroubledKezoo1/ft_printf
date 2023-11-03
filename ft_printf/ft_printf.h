/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:15:55 by ysarac            #+#    #+#             */
/*   Updated: 2023/11/03 17:56:03 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

static int	ft_putstr(char *str, int i);
int			put_digit(long long int number, char *base, int bsize);
static int	ft_formats(va_list args, const char formats);
int			put_digit_pointer(unsigned long int number, char *base, int bsize);
int			ft_printf(const char *format, ...);
#endif