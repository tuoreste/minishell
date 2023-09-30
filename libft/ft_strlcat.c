/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:56 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 22:18:14 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t d)
{
	size_t	i;
	size_t	j;
	size_t	l1;
	size_t	l2;

	j = 0;
	i = ft_strlen(dst);
	l2 = i;
	l1 = ft_strlen(src);
	if (d == 0)
		return (l1);
	while (src[j] != '\0' && i < d - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < d)
		dst[i] = '\0';
	if (l2 < d)
		return (l1 + l2);
	else
		return (l1 + d);
}
