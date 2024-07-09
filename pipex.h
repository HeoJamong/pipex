#ifndef PIPEX
# define PIPEX

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	char	**cmd1;
	char	**cmd2;
	char	**path;
	pid_t	pid;
	int		fds[2];
	int		i;
}t_data;


void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
#endif