/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:54:39 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/01 03:41:18 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*r;

	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (r == NULL || !s1 || !s2)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		r[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}
