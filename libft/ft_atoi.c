/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:15 by aguediri          #+#    #+#             */
/*   Updated: 2023/04/16 21:17:10 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	checker(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	s;

	i = 0;
	n = 0;
	s = 1;
	while (str[i] && checker(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] <= '9' && str[i] >= '0')
		{
			if (str[i - 1] == '-')
				s = -1;
		}
		else
			return (0);
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * s);
}
