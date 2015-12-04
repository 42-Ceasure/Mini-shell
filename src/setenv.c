#include "shell.h"

char		**add_env(t_env *e, char *lel, size_t i)
{
	char	**tmp;

	tmp = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	i = 0;
	while (e->env[i])
	{
		tmp[i] = ft_strdup(e->env[i]);
		i++;
	}
	tmp[i] = ft_strdup(lel);
	memreg(e->env);
	return (tmp);
}

void		do_mod(t_env *e, size_t mem, char *lol, char *lel)
{
	if (mem == 1)
		usefull_vars(e, e->i);
	if (mem == 0)
	{
		e->env = add_env(e, lel, e->i);
		e->i = 0;
		re_usefull_vars(e);
	}
	free(lol);
	free(lel);
}

void		modif_env(t_env *e, char *var, char *val)
{
	size_t	mem;
	int		varl;
	char	*lol;
	char	*lel;

	lol = ft_strjoin(var, "=");
	lel = ft_strjoin(lol, val);
	e->i = 0;
	mem = 0;
	varl = ft_strlen(var);
	while (e->env[e->i])
	{
		if (!strncmp(e->env[e->i], lol, varl + 1))
		{
			free(e->env[e->i]);
			e->env[e->i] = ft_strdup(lel);
			mem = 1;
			break ;
		}
		e->i++;
	}
	do_mod(e, mem, lol, lel);
}

void		check(t_env *e, char **tmp, char *var, char *val)
{
	if (e->av[1] && e->av[2])
	{
		var = ft_strdup(e->av[1]);
		val = ft_strdup(e->av[2]);
	}
	else if (e->av[1] && !e->av[2])
	{
		if (strchr(e->av[1], '=') != NULL)
		{
			tmp = ft_strsplit(e->av[1], '=');
			while (tmp[e->i])
				e->i++;
			var = ft_strdup(tmp[0]);
			if (e->i == 2)
				val = ft_strdup(tmp[1]);
			memreg(tmp);
		}
		else
			var = ft_strdup(e->av[1]);
	}
	else
		ft_putendl("use setenv <var>=<val>\nor setenv <var> <val>");
	if (var)
		modif_env(e, var, val);
	free(var);
	free(val);
}

void		ft_setenv(t_env *e)
{
	char	*var;
	char	*val;
	char	**tmp;

	e->i = 0;
	var = NULL;
	val = NULL;
	tmp = NULL;
	if (e->av[1])
	{
		check(e, tmp, var, val);
	}
	else
		ft_putendl("use setenv <var>=<val>\nor setenv <var> <val>");
}
