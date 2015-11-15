#include "shell.h"

void		parse_env(t_env *e, char **ep)
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
