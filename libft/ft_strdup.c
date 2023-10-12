/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:15 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/01 03:43:49 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*c;

	i = ft_strlen(s1);
	c = (char *) malloc((i + 1) * sizeof (char));
	if (c != NULL)
		ft_memcpy(c, s1, i + 1);
	return (c);
}
