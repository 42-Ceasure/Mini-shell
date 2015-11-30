
#include "shell.h"

// void recalc_env(t_env *e);
// {

// }

// void recalc_pwd(t_env *e);
// {
// 	char *tmp;

// 	tmp = e->pwd;
// }

void memreg(char **s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
	}
	free(s);
}