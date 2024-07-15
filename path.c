/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:01:02 by jheo              #+#    #+#             */
/*   Updated: 2024/07/15 22:27:12 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_control(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
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

char	*command_path_check(t_data *t, char	**cmd)
{
	int		i;
	char	*command;
	char	*temp;

	i = 0;
	if (cmd[0][0] != '/')
	{
		while (t->path[i])
		{
			temp = ft_strjoin(t->path[i], "/");
			command = ft_strjoin(temp, cmd[0]);
			free(temp);
			if (access(command, F_OK | X_OK) == 0)
			{
				return (command);
			}
			free(command);
			i++;
		}
	}
	return (cmd[0]);
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
			break ;
		}
		i++;
	}
	t->path = ft_split(path, ':');
}
