/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/02 17:59:29 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_up(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	printenvList(t_env *envlist)
{
	t_env	*current;

	current = envlist;
	while (current != NULL)
	{
		printf("%s\n", current->l);
		current = current->next;
	}
}

void	ft_lstaddback(t_env **lst, t_env *new)
{
	t_env	*t;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next != NULL)
		t = t->next;
	t->next = new;
}
void	ft_init(char **env, t_env *envlist)
{
	t_env	*element;
	int		i;

	i = 0;
	while (env[i])
	{
		element = (t_env *)malloc(ft_strlen(env[i]));
		element->l = ft_strdup(env[i]);
		ft_lstaddback(&envlist, element);
		i++;
	}
//	printenvList(envlist);
}

void	ft_getactivepath(t_data *data)
{
	int	i;

	i = 0;
	i = pathconf(".", _PC_PATH_MAX);
	data->path = (char *)malloc(i);
	getcwd(data->path, i);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*envlist;
	t_data	*data;

	if (argc < 1)
		printf("fbkk");
	if (argv[0])
		printf("useless\n");
	envlist = NULL;
	data = NULL;
	ft_init(env, envlist);
	ft_getactivepath(data);
	printf("\n\n%s\n\n", data->path);
}
