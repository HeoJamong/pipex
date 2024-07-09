#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	find_path(char	*envp)
{
	char	*path;
	int		index;

	index = 0;
	path = "PATH";
	while (path[index])
	{
		if (envp[index] != path[index])
			return (-1);
		index++;
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	char	*path;
	i = 0;
	while (envp[i])
	{
		if (find_path(envp[i]) == 1)
			printf("%s", envp[i]);
		i++;
	}
	return (0);
}