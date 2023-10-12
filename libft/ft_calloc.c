/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:09 by aguediri          #+#    #+#             */
/*   Updated: 2023/03/25 21:06:05 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *str, int c, int n)
{
	int				i;
	unsigned char	*p;
	char			v;

	p = str;
	v = (char)c;
	i = 0;
	while (i < n)
	{
		*p++ = v;
		i++;
	}
	return (str);
}

void	*ft_calloc(int count, int size)
{
	int		t;
	void	*ptr;

	t = count * size;
	ptr = (int *) malloc (t);
	if (ptr)
		ft_memset(ptr, 0, t);
	return (ptr);
}
