/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:37 by aguediri          #+#    #+#             */
/*   Updated: 2023/03/22 15:46:54 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int				i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	i = 0;
	char_s1 = (unsigned char *) s1;
	char_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i])
		{
			return (char_s1[i] - char_s2[i]);
		}
		i++;
	}
	return (0);
}
