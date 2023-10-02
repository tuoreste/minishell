/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:52:10 by aguediri          #+#    #+#             */
/*   Updated: 2023/10/02 12:04:28 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
/*c standard libraries*/
# include <stdio.h>
# include <dirent.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
/*other*/
# include "executer/executer.h"
# include "parser/parser.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

/*linked list*/
typedef struct s_env
{
	char			*l;
	struct s_env	*next;
}					t_env;
typedef struct s_data
{
	char *path;
	
} t_data;
#endif