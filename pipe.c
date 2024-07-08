/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:51:24 by jheo              #+#    #+#             */
/*   Updated: 2024/07/04 16:52:31 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling()
{
	perror("Error");
	eixt(EXIT_FAILURE);
}

void	read_file(void	*read_file, char *argv[])
{
	int	fd;

	if (access(argv[1], F_OK) == -1)
		perror("그런 파일이나 디렉토리가 없습니다.");
	else
	{
		if (fd = open(argv[1], O_RDONLY) < 0)
			error_handling();
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	void	*read_file;

	if (argc < 6)
		error_handling();
	if (pid == -1)
		error_handling();
	read_file(&read_file, argv[1]);
	return (0);
}
