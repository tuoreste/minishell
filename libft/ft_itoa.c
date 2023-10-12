/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:55:11 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 21:23:14 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	digitc( int n)
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

char	*ft_itoa(int n)
{
	char	*c;
	int		j;
	int		s;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = digitc(n);
	c = ft_calloc((digitc(n) + 1), sizeof(char));
	if (!c)
		return (NULL);
	if (n < 0)
	{
		c[0] = '-';
		n = n * (-1);
		s = 1;
	}
	while (j > s)
	{
		c[j - 1] = (n % 10) + '0';
		j--;
		n = n / 10;
	}
	return (c);
}
