#include "shell.h"

void parse_cmd(t_env *e, int ac, char **av, char **ep, char *buf)
{
	(void)av;
	(void)ep;
	(void)ac;
	char *lol;
	lol = ft_epur_tabul(buf);
	e->av = ft_strsplit(lol, ' ');
}