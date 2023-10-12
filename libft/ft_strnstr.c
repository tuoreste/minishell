/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:11 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 21:37:35 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= len && h[i])
	{
		j = 0;
		while (j + i < len && n[j] && h[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return ((char *)h + i);
			j++;
		}
		i++;
	}
	if (*n == '\0')
		return ((char *)h);
	return (NULL);
}
