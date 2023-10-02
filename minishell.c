/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/02 14:12:32 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
void	ft_init(char *envv, t_env *envlist)
{
	t_env	*element;
	int		i;
	int		j;
	char	**env;

	env = NULL;
	env = ft_split(envv, '\n');
	j = 0;
	element = malloc(sizeof(t_env));
	i = 0;
	while (*env[i])
	{
		j = 0;
		while (env[i][++j])
			element->l[j] = env[i][j];
		ft_lstaddback(&envlist, element);
		i++;
	}
}
void	ft_getactivepath(t_data *data)
{
	int	i;

	i = 0;
	i = pathconf(".", _PC_PATH_MAX);
	data->path = (char *)malloc(i);
	getcwd(data->path, i);
}

int	main(void)
{
	t_env	*envlist;
	t_data	*data;
	char	*env;
	char	*envv;

	env = NULL;
	envv = NULL;
	envv = getenv(env);
	printf("%s", envv);
	envlist = NULL;
	data = NULL;
	ft_init(env, envlist);
}
