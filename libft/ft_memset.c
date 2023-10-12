/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:46 by aguediri          #+#    #+#             */
/*   Updated: 2023/03/19 21:27:08 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, int n)
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
