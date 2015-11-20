
#include "shell.h"

// void recalc_env(t_env *e);
// {

// }

// void recalc_pwd(t_env *e);
// {
// 	char *tmp;

// 	tmp = e->pwd;
// }

void memreg(t_env *e, char *buf)
{
	free(e->av);
	free(buf);
}