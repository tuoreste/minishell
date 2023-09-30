/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:54:22 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/13 03:43:21 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*c;
	unsigned int		i;
	unsigned int		j;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	c = (char *)malloc((len + 1) * sizeof(char));
	i = start;
	j = 0;
	if (c == NULL)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		c[j] = s[i];
		i++;
		j++;
	}
	c[j] = '\0';
	return (c);
}
