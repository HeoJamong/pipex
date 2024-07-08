#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char **envp)
{
	char	*path;
	char	**argument;

	if (access(argv[1], F_OK) == 0)
		write(1, "b\n", 2);
	argument = (char **)malloc(sizeof(char *)*2);
	argument[0] = "ls";
	argument[1] = "-l";
	path = ("/usr/bin/ls");
	execve(path, argument, envp);
	perror("Error");
	exit(EXIT_FAILURE);
}