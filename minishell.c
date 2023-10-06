/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:06 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/06 13:35:17 by aguediri         ###   ########.fr       */
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
void ft_init(char **env, t_env **envlist)
{
    t_env *element;
    int i;

    i = 0;
    while (env[i])
    {
        element = (t_env *)malloc(sizeof(t_env)); // Allocate memory for the entire t_env structure
        if (element)
        {
            element->l = ft_strdup(env[i]);
            element->next = NULL; // Initialize the 'next' pointer
            ft_lstaddback(envlist, element);
        }
        i++;
    }
     printenvList(*envlist);
}

void	ft_getactivepath(t_data *data)
{
	size_t	i;
	char	*s;

	i = pathconf(".", _PC_PATH_MAX);
	s = (char *)malloc((size_t)i);
	data = (t_data *)malloc(sizeof(t_data));
	if (!s)
		return ;
	printf("%ld\n", i);
	s = getcwd(s, i);
	if (s)
		data->path = ft_strdup(s);
	else
		printf("qwwd");
	printf("%s", s);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*envlist;
	t_data	*data;

	if (argc < 1)
		printf("fbkk");
	if (argv[0])
		printf("useless\n");
	data = NULL;
	envlist = NULL;
	ft_init(env, &envlist);
	ft_getactivepath(data);
}
