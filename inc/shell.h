

#ifndef FT_SH1_H
# define FT_SH1_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct	s_env
{
	char	**env;
	char	**av;
	int		ac;
}				t_env;

void parse_env(t_env *e, int ac, char **av, char **ep);
void ft_prompt(t_env *e);

#endif
