/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:47:52 by otuyishi          #+#    #+#             */
/*   Updated: 2023/10/03 19:24:42 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_interrupt(int signal)
{
	if (signal == SIGINT)
	{
		printf("\nCtrl+C detected. Exiting...\n");
		exit(EXIT_SUCCESS);
	}
}

void	init_termios(struct termios *saved_attributes)
{
	struct termios	new_attributes;

	if (tcgetattr(STDIN_FILENO, saved_attributes) == -1)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	new_attributes = *saved_attributes;
	new_attributes.c_lflag &= ~(ICANON);
	new_attributes.c_cc[VMIN] = 1;
	new_attributes.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_attributes) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

void	restore_termios(struct termios *saved_attributes)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, saved_attributes) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
}

char	*read_command(void)
{
	char	*input;
	size_t	input_size;
	ssize_t	read_bytes;

	input = NULL;
	input_size = 0;
	printf(">> ");
	read_bytes = getline(&input, &input_size, stdin);
	if (read_bytes == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	input[strcspn(input, "\n")] = '\0';
	return (input);
}

void	execute_command(char *command)
{
	int		fd[2];
	pid_t	child_pid;
	char	buffer[4096];
	ssize_t	read_bytes;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execlp("/bin/sh", "/bin/sh", "-c", command, NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		waitpid(child_pid, NULL, 0);
		while ((read_bytes = read(fd[0], buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, read_bytes);
		close(fd[0]);
	}
}

int	termio(void)
{
	struct termios	saved_attributes;
	char			*command;

	signal(SIGINT, handle_interrupt);
	init_termios(&saved_attributes);
	while (1)
	{
		//printf("Welcome to my minishell!\n");
		command = read_command();
		if (ft_memcmp(command, "exit", 4) == 0)
		{
			free(command);
			break ;
		}
		execute_command(command);
		free(command);
	}
	restore_termios(&saved_attributes);
	return (0);
}
