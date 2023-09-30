/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/30 14:54:23 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(char **env, t_env *envlist)
{
	t_env	*element;
	int		i;

	element = malloc(sizeof(t_env));
	i = 0;
	while (*env[i])
	{
		element->l = *env[i];
		ft_lstadd_back(envlist, element);
		i++;
	}
}

int	main(char **env)
{
	t_env *envlist;

	envlist = NULL;
	ft_init(env, envlist);
}
