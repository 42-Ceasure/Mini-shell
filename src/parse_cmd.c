
#include "shell.h"

void			check_tild_minus(t_env *e, size_t z)
{
	size_t		i;
	char		*tmp;
	char		*lol;

	tmp = NULL;
	lol = NULL;
	i = ft_strlen(e->av[z]);
	if (i == 1 && !strncmp(e->av[z], "~", 1))
	{
		if (*g_home)
		{
			free(e->av[z]);
			e->av[z] = ft_strdup(*g_home);
		}
	}
	else if (i > 1 && !strncmp(e->av[z], "~/", 2))
	{
		if (*g_home)
		{
			tmp = ft_strsub(e->av[z], 1, (ft_strlen(e->av[z]) - 1));
			lol = ft_strjoin(*g_home, tmp);
			free(e->av[z]);
			e->av[z] = ft_strdup(lol);
			free(tmp);
			free(lol);
		}
	}
	else if (i == 1 && !strncmp(e->av[z], "-", 1))
	{
		if (*g_oldpwd)
		{
			free(e->av[z]);
			e->av[z] = ft_strdup(*g_oldpwd);
		}
	}
	else if (i > 1 && !strncmp(e->av[z], "-/", 2))
	{
		if (*g_oldpwd)
		{
			tmp = ft_strsub(e->av[z], 1, (ft_strlen(e->av[z]) - 1));
			lol = ft_strjoin(*g_oldpwd, tmp);
			free(e->av[z]);	
			e->av[z] = ft_strdup(lol);
			free(tmp);
			free(lol);
		}
	}
}

void			parse_cmd(t_env *e, char *buf)
{
	memreg(e->av);
	e->av = ft_strsplit(buf, ' ');
	if (e->av[1])
		check_tild_minus(e, 1);
}
