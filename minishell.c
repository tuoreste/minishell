/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/09/30 14:46:39 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_init(char **env, t_env *envlist)
{
    t_env *element;

    element = malloc(sizeof(t_env));
    int i = 0 ;
    while (*env[i])
    {
        element->l = *env[i];
        ft_lstadd_back(envlist,element);
        i++;
    }
    
}
int main (char **env)
{
    t_env *envlist;

    envlist = NULL;
    ft_init(env, envlist);
}