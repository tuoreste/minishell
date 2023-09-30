/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:33 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 21:42:02 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*p;
	char	ch;

	p = (char *) str;
	ch = (char) c;
	while (n-- > 0)
	{
		if (*p == ch)
			return (p);
		p++;
	}
	return (0);
}
