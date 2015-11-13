#include "shell.h"

void		arv(t_env *e, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i] != NULL)
		i++;
	e->av = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			j++;
		e->av[i] = (char *)malloc(sizeof(char) * j + 1);
		ft_strcpy(e->av[i], av[i]);
		i++;
	}
}

void		erp(t_env *e, char **ep)
{
	int		i;
	int		j;

	i = 0;
	while (ep[i] != NULL)
		i++;
	e->env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (ep[i])
	{
		j = 0;
		while (ep[i][j])
			j++;
		e->env[i] = (char *)malloc(sizeof(char) * j + 1);
		ft_strcpy(e->env[i], ep[i]);
		i++;
	}
}

void		parse_env(t_env *e, int ac, char **av, char **ep)
{
	e->ac = ac;
	arv(e, av);
	erp(e, ep);
}
