/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:10 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/07 14:02:50 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/*c standard libraries*/
# include <dirent.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
/*other*/
# include "executer/executer.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "parser/parser.h"

/*linked list*/
typedef struct s_env
{
	char			*l;
	struct s_env	*next;
}					t_env;
typedef struct s_data
{
	char			*path;

}					t_data;

// history
# define MAX_BUFFER_SIZE 1024
# define MAX_HISTORY_SIZE 100

typedef struct s_cmd_history
{
	char			history[MAX_HISTORY_SIZE][MAX_BUFFER_SIZE];
	int				history_index;
	int				history_size;
}					t_cmd_hist;

#endif