#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**argument;

	argument = (char **)malloc(sizeof(char *) * 2);
	argument[0] = "ls";
	argument[1] = "-l";
	path = "/pipex/execve";
	execve(path, argument, envp);
	exit(0);
	return (0);
}