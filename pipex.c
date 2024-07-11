/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:51:24 by jheo              #+#    #+#             */
/*   Updated: 2024/07/11 17:33:36 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling()
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	input_file_check(char *input_file)
{
	if (access(input_file, F_OK | R_OK) == 0)
		write(1, "good\n", 5);
	else
		error_handling();
}
int	find_path(char	*envp)
{
	char	*path;
	int		i;

	path = "PATH";
	i = 0;
	while (path[i])
	{
		if (envp[i] != path[i])
			return (-1);
		i++;
	}
	return (1);
}

int	command_path_check(t_data *t, char	**cmd)
{
	int	i;
	char *command;

	i = 0;
	if (cmd[0][0] != '/')
	{
		while (t->path[i])
		{
			command = ft_strjoin(t->path[i], "/");
			command = ft_strjoin(command,cmd[0]);
			if (access(command, F_OK | X_OK) == 0)
			{
				t->command = command;
				return(1);
			}
			free(command);
			i++;
		}
	}
	return (-1);
}

void	path_split(t_data *t, char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (find_path(envp[i]) == 1)
		{
			path = (envp[i] + 5);
			break;
		}
		i++;
	}
	t->path = ft_split(path, ':');
}

void	pipex(t_data *t, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];
	
	if (pipe(fd) == -1)
		perror("pipe error");
	pid = fork();
	if (pid == -1)
		error_handling();
	else if (pid == 0)
	{
		t->input_file = open(argv[0], O_RDONLY);
		if (t->input_file > 0)
		{
			dup2(fd[1], 1);
			dup2(t->input_file, 0);
			execve(t->command, t->cmd1, envp);
		}
	}
	else
	{
		pid = fork();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	t;
	
	(void)argc;
	pipe(t.fds);
	t.cmd1 = ft_split(argv[2], ' ');
	t.cmd2 = ft_split(argv[3], ' ');
	path_split(&t, envp);
	return (0);
}
