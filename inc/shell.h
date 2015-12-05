
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

// # define PATH_MAX 1024

typedef struct	s_env
{
	char	**env;
	char	**av;
	size_t	i;
}				t_env;

char	**g_pwd;
char	**g_oldpwd;
char	**g_home;
char	**g_paths;

void	ft_swagg(char *s);
void	prompt(void);

void	handler(int sig);

void	parse_env(t_env *e, char **ep);
void	parse_cmd(t_env *e, char *buf);
void	inspection(t_env *e);
void	chk_n_ex_cmd(t_env *e);

void	modif_env(t_env *e, char *var, char *val);
void	usefull_vars(t_env *e, size_t i);
void	re_usefull_vars(t_env *e);
void	ft_setenv(t_env *e);
void	ft_unsetenv(t_env *e);
void	print_env(t_env *e);
void	print_vars(t_env *e);



#endif
