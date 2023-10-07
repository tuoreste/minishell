/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:18:01 by otuyishi          #+#    #+#             */
/*   Updated: 2023/10/07 14:13:42 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd_hist(t_cmd_hist *history)
{
	history->history_index = 0;
	history->history_size = 0;
}

void	add_to_history(t_cmd_hist *history, const char *command)
{
	int	i;

	i = 0;
	if (history->history_size < MAX_HISTORY_SIZE)
	{
		ft_strcpy(history->history[history->history_size], command);
		history->history_size++;
	}
	else
	{
		while (i < MAX_HISTORY_SIZE - 1)
		{
			ft_strcpy(history->history[i], history->history[i + 1]);
			i++;
		}
		ft_strcpy(history->history[MAX_HISTORY_SIZE - 1], command);
	}
}
