
#include "shell.h"

void		print_env(t_env *e)
{
	int i;

	i = 0;
	if (e->env)
	{
		while (e->env[i])
		{
			ft_putendl(e->env[i]);
			i++;
		}
	}
}

void		print_vars(t_env *e)
{
	char 	**path;

	path = g_paths;
	if (!ft_strcmp(e->av[1], "pwd"))
		ft_putendl(*g_pwd);
	else if (!ft_strcmp(e->av[1], "old_pwd"))
		ft_putendl(*g_oldpwd);
	else if (!ft_strcmp(e->av[1], "home"))
		ft_putendl(*g_home);
	else if (!ft_strcmp(e->av[1], "paths"))
	{
		if (path)
			while (*path)
				ft_putendl(*path++);
	}
	ft_putchar('\n');
}
