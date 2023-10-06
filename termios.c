/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:47:52 by otuyishi          #+#    #+#             */
/*   Updated: 2023/10/06 13:28:24 by otuyishi         ###   ########.fr       */
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

void	custom_clear(void)
{
	if (isatty(STDOUT_FILENO))
	{
		const char *clear_sequence = "\x1b[H\x1b[2J";
		write(STDOUT_FILENO, clear_sequence, strlen(clear_sequence));
	}
}

char	*find_command_in_path(const char *command_name)
{
	char	*path;
	char	*path_copy;
	char	*token;
	char	*full_path;

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command_name) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command_name);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

void	execute_command(char *command)
{
	int		fd[2];
	pid_t	child_pid;
	char	buffer[4096];
	ssize_t	read_bytes;
	char	*token;
	int		arg_count;
	char	*full_path;
	char	**args;

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
		token = strtok(command, " ");
		args = NULL;
		arg_count = 0;
		while (token != NULL)
		{
			args = realloc(args, sizeof(char *) * (arg_count + 1));
			if (args == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args = realloc(args, sizeof(char *) * (arg_count + 1));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		args[arg_count] = NULL;
		full_path = find_command_in_path(args[0]);
		if (full_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
		execve(full_path, args, NULL);
		perror("execve");
		free(args);
		free(full_path);
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

int	main(int argc, char **argv, char **env)
{
	struct termios	saved_attributes;
	char			*command;

	signal(SIGINT, handle_interrupt);
	init_termios(&saved_attributes);
	while (1)
	{
		// printf("Welcome to my minishell!\n");
		command = read_command();
		if (ft_memcmp(command, "exit", 4) == 0)
		{
			free(command);
			break ;
		}
		else if (strcmp(command, "clear") == 0)
			custom_clear();
		execute_command(command);
		free(command);
	}
	restore_termios(&saved_attributes);
	return (0);
}
