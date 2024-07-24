/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:02:59 by jheo              #+#    #+#             */
/*   Updated: 2024/07/24 18:28:09 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	pid_t	pid1;
	pid_t	pid2;
	int		input_file;
	int		out_file;
	char	*cmd_path1;
	char	*cmd_path2;
}t_data;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		find_path(char	*envp);
char	*command_path_check(t_data *t, char	**cmd);
void	path_split(t_data *t, char *envp[]);
void	error_control(char *s);
#endif