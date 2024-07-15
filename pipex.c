/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:51:24 by jheo              #+#    #+#             */
/*   Updated: 2024/07/15 22:27:06 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	all_clean(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	first_child(t_data *t, char *argv[], char *envp[], int fd[])
{
	t->input_file = open(argv[1], O_RDONLY);
	if (t->input_file == -1)
	{
		perror("open error");
		return ;
	}
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		error_control("dup error");
	if (dup2(t->input_file, 0) == -1)
		error_control("dup error");
	close(fd[1]);
	close(t->input_file);
	if (execve(command_path_check(t, t->cmd1), t->cmd1, envp) == -1)
		error_control("execve error");
}

void	second_child(t_data *t, char *argv[], char *envp[], int fd[])
{
	t->out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (t->out_file == -1)
	{
		perror("open error");
		return ;
	}
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		error_control("dup error");
	if (dup2(t->out_file, 1) == -1)
		error_control("dup error");
	close(fd[0]);
	close(t->out_file);
	if (execve(command_path_check(t, t->cmd2), t->cmd2, envp) == -1)
		error_control("execve error");
}

void	pipex(t_data *t, char *argv[], char *envp[])
{
	int		fd[2];

	if (pipe(fd) == -1)
		error_control("pipe error");
	t->pid1 = fork();
	if (t->pid1 == -1)
		error_control("fork error");
	else if (t->pid1 == 0)
		first_child(t, argv, envp, fd);
	else
	{
		t->pid2 = fork();
		if (t->pid2 == -1)
			error_control("fork error");
		else if (t->pid2 == 0)
			second_child(t, argv, envp, fd);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(t->pid1, NULL, 0);
			waitpid(t->pid2, NULL, 0);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	t;

	if (argc != 5)
		exit(EXIT_FAILURE);
	t.cmd1 = ft_split(argv[2], ' ');
	t.cmd2 = ft_split(argv[3], ' ');
	path_split(&t, envp);
	pipex(&t, argv, envp);
	all_clean(t.cmd1);
	all_clean(t.cmd2);
	return (0);
}
