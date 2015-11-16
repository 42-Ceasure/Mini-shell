#include "shell.h"

void		print_env(t_env *e)
{
	if (e->env)
	{
		while (*e->env)
			ft_putendl(*e->env++);
	}
}

void		print_vars(t_env *e)
{
	if (e)
	{
		ft_putendl(*e->pwd);
		ft_putendl(*e->oldpwd);
		ft_putendl(*e->home);
		ft_putendl(*e->paths);
	}
}

void		parse_env(t_env *e, char **ep)
{
	int		i;
	int		j;

	i = 0;
	while (ep[i] != NULL)
		i++;
	e->env = (char **)malloc(sizeof(char *) * i + 1);
	e->pwd = (char **)malloc(sizeof(char *));
	e->oldpwd = (char **)malloc(sizeof(char *));
	e->home = (char **)malloc(sizeof(char *));
	e->paths = (char **)malloc(sizeof(char *));
	i = 0;
	while (ep[i])
	{
		j = 0;
		while (ep[i][j])
			j++;
		e->env[i] = ft_strdup(ep[i]);
		if (!ft_strncmp(e->env[i], "PWD=", 4))
			*e->pwd = &e->env[i][4];
		else if (!ft_strncmp(e->env[i], "OLDPWD=", 7))
			*e->oldpwd = &e->env[i][7];
		else if (!ft_strncmp(e->env[i], "HOME=", 5))
			*e->home = &e->env[i][5];
		else if (!ft_strncmp(e->env[i], "PATH=", 5))
			*e->paths = &e->env[i][5];
		i++;
	}
}
