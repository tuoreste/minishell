/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:43:16 by aguediri          #+#    #+#             */
/*   Updated: 2023/05/14 23:32:14 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatter(char i, va_list arg)
{
	int	j;

	j = 0;
	if (i == 'c')
		j += ft_putchar(va_arg(arg, long int), 1);
	else if (i == 's')
		j += ft_putstr(va_arg(arg, char *), 1);
	else if (i == '%')
		j += ft_putchar('%', 1);
	else if (i == 'x' || i == 'X')
	{
		j += ft_tohex_x(va_arg(arg, unsigned int), i);
	}
	else if (i == 'p')
	{
		j += ft_putstr("0x", 1);
		j += ft_tohex_p(va_arg(arg, unsigned long));
	}
	else if (i == 'u')
		j += ft_putnbru(va_arg(arg, unsigned int), 1);
	else if (i == 'd' || i == 'i')
		j += ft_putnbr(va_arg(arg, int), 1);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	l;

	va_start(l, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j += ft_formatter(format[i], l);
		}
		else
			j += ft_putchar(format[i], 1);
		i++;
	}
	va_end(l);
	return (j);
}
