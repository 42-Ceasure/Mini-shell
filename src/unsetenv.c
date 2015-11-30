#include "shell.h"

char		**new_env(t_env *e, char *lol, size_t i)
{
	char	**tmp;
	int		varl;

	tmp = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	varl = ft_strlen(lol);
	while (e->env[i])
	{
		if (!ft_strncmp(e->env[i], lol, varl))
		{
			tmp[i] = ft_strdup(e->env[i]);
			ft_putendl("ooo");
			i++;
		}
		ft_putendl("=(");
		tmp[i] = ft_strdup(e->env[i + 1]);
		i++;
	}
	ft_putendl("lol");
	memreg(e->env);
	return (tmp);
}

void		ft_unsetenv(t_env *e)
{
	char	*var;
	char	*lol;

	e->i = 0;
	var = ft_strdup(e->av[1]);
	lol = ft_strjoin(var, "=");
	while (e->env[e->i])
		e->i++;
	if (e->av[1])
	{
		e->env = new_env(e, lol, (e->i - 1));
		e->i = 0;
		while (e->env[e->i])
		{
			usefull_vars(e, e->i);
			e->i++;
		}
	}
	else
		ft_putendl("use unsetenv <var>");
	free(lol);
	free(var);
	prompt(e);
}