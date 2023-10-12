/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:18:01 by otuyishi          #+#    #+#             */
/*   Updated: 2023/10/09 14:02:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	init_cmd_hist(t_cmd_hist *history)
// {
// 	history->history_index = 0;
// 	history->history_size = 0;
// }
//----------------------------------------------
// void ft_lstaddh(t_cmd_hist **lst, t_cmd_hist *new)
// {
//     if (new == NULL)
//         return;
    
//     new->next = *lst;
//     *lst = new;
// }



// void	add_to_history(t_cmd_hist *history, const char *command)
// {
// 	int	i;
// 	t_cmd_hist *cmd;

// 	i = 0;
// 	if (history->history_size < MAX_HISTORY_SIZE)
// 	{
// 		cmd = (t_cmd_hist*)malloc(sizeof(t_cmd_hist));
// 		ft_strlcpy(cmd->history[history->history_size], command, );
// 		ft_lstaddh(&history,cmd);
// 		history->history_size++;
// 	}
// 	else
// 	{
// 		while (i < MAX_HISTORY_SIZE - 1)
// 		{
// 			ft_strcpy(history->history[i], history->history[i + 1]);
// 			i++;
// 		}
// 		ft_strcpy(cmd->history[MAX_HISTORY_SIZE - 1], command);
// 		ft_lstaddh(&history,cmd);
// 	}
// }
