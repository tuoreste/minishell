/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:23:33 by aguediri          #+#    #+#             */
/*   Updated: 2023/05/14 23:31:59 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)", 1));
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

char	ft_hex_u( unsigned int n, char c)
{
	if (n <= 9)
		return (n + '0');
	else if (c == 'x')
		return (n - 10 + 'a');
	else if (c == 'X')
		return (n - 10 + 'A');
	else
		return (0);
}

int	ft_tohex_x(unsigned int n, char c)
{
	int		i;
	int		j;
	int		d;
	char	*s;

	i = 0;
	j = 0;
	d = 0;
	s = malloc(10);
	if (n == 0)
	{
		ft_putchar('0', 1);
		free(s);
		return (1);
	}
	while (n > 0)
	{
		s[i] = ft_hex_u(n % 16, c);
		i++;
		n /= 16;
	}
	while (i > 0)
			j += ft_putchar(s[--i], 1);
	free(s);
	return (j);
}

int	ft_tohex_p(unsigned long n)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (n == 0)
	{
		ft_putchar('0', 1);
		return (1);
	}
	s = malloc(32);
	while (n > 0)
	{
		if (n % 16 <= 9)
			s[i] = n % 16 + '0';
		else
			s[i] = n % 16 - 10 + 'a';
		i++;
		n /= 16;
	}
	while (i > 0)
			j += ft_putchar(s[--i], 1);
	free(s);
	return (j);
}
