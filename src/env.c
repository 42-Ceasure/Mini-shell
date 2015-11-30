#include "shell.h"

void		ft_setenv(t_env *e)
{
	int		i;
	char	*var;
	char	*val;
	char	**tmp;

	i = 0;
	var = NULL;
	val = NULL;
	tmp = NULL;
	if (e->av[1])
	{
		if (strchr(e->av[1], '=') != NULL)
		{
			tmp = ft_strsplit(e->av[1], '=');
			while (tmp[i])
				i++;
			if (i != 2)
				ft_putendl("KO");
			else
			{
				var = ft_strdup(tmp[0]);
				val = ft_strdup(tmp[1]);
			}
			ft_putstr(var);
			ft_putchar('=');
			ft_putendl(val);
			memreg(tmp);
			free(var);
			free(val);
		}
		else if (e->av[2])
		{
			var = ft_strdup(e->av[1]);
			val = ft_strdup(e->av[2]);
			ft_putstr(var);
			ft_putchar('=');
			ft_putendl(val);
			free(var);
			free(val);
		}
		else
			ft_putendl("use setenv <var>=<val>\nor setenv <var> <val>");	
	}
	else
		ft_putendl("use setenv <var>=<val>\nor setenv <var> <val>");
	prompt(e);
}

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
	ft_putchar('\n');
	prompt(e);
}

void		print_vars(t_env *e)
{
	char 	**path;

	path = e->paths;
	if (!ft_strcmp(e->av[1], "pwd"))
		ft_putendl(*e->pwd);
	else if (!ft_strcmp(e->av[1], "old_pwd"))
		ft_putendl(*e->oldpwd);
	else if (!ft_strcmp(e->av[1], "home"))
		ft_putendl(*e->home);
	else if (!ft_strcmp(e->av[1], "paths"))
	{
		while (*path)
		{
			ft_putendl(*path++);
		}
	}
	ft_putchar('\n');
	prompt(e);
}

void		parse_env(t_env *e, char **ep)
{
	int		i;
	int		j;

	i = 0;
	while (ep[i] != NULL)
		i++;
	e->env = (char **)ft_memalloc(sizeof(char *) * i + 1);
	e->pwd = (char **)ft_memalloc(sizeof(char *));
	e->oldpwd = (char **)ft_memalloc(sizeof(char *));
	e->home = (char **)ft_memalloc(sizeof(char *));
	e->paths = NULL;
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
		{
			e->paths = ft_strsplit(&e->env[i][5], ':');
		}
		i++;
	}
}
