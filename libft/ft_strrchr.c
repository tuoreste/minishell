/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:57:14 by aguediri          #+#    #+#             */
/*   Updated: 2023/03/25 00:57:58 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(char *s, char n)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == n)
			return (&s[i]);
		i--;
	}
	return (0);
}
