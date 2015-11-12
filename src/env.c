#include "shell.h"

char **parse_env(char **ep)
{
	int i;
	int j;
	char **env;

	i = 0;
	while (ep[i] != NULL)
		i++;
	env = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (ep[i])
	{
		j = 0;
		while (ep[i][j])
			j++;
		env[i] = (char *)malloc(sizeof(char) * j + 1);
		ft_strcpy(env[i], ep[i]);
		i++;
	}
	return (env);
}
