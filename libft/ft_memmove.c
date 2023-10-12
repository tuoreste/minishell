/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:43 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/11 22:08:32 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int n)
{
	int					i;
	unsigned char		*char_dst;
	unsigned const char	*char_src;

	i = 0;
	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	if (char_dst < char_src)
	{
		while (i < n)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	}
	else if (char_dst > char_src)
	{
		i = n;
		while (i-- > 0)
		{
			char_dst[i] = char_src[i];
		}
	}
	return (dst);
}
