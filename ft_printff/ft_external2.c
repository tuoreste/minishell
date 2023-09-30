/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_external2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:23:33 by aguediri          #+#    #+#             */
/*   Updated: 2023/05/14 22:55:30 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_digitcu( unsigned int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i + j);
}

int	ft_digitc(int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i + j);
}

int	isnegative(int n)
{
	write(1, "-", 1);
	return (-n);
}

int	ft_putnbr(int n, int fd)
{
	char	m;
	int		i;

	i = ft_digitc(n);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = isnegative(n);
	}
	if (n < 10 && n >= 0)
	{
		m = n + '0';
		write(fd, &m, 1);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10, fd);
		m = n % 10 + '0';
		write(fd, &m, 1);
	}
	return (i);
}

int	ft_putnbru(unsigned int n, int fd)
{
	char	m;
	int		i;

	i = ft_digitcu(n);
	if (n < 10 && n >= 0)
	{
		m = n + '0';
		write(fd, &m, 1);
	}
	else if (n > 9)
	{
		ft_putnbru(n / 10, fd);
		m = n % 10 + '0';
		write(fd, &m, 1);
	}
	return (i);
}
