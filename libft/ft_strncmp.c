/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:08 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 21:31:04 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char )s1[i] != (unsigned char )s2[i])
		{
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char )s1[i] - (unsigned char )s2[i]);
}
