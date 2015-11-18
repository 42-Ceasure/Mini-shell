
#include "shell.h"

int main(int ac, char **av, char **ep)
{
	t_env *e;
	char 	*buf;

(void)ac;
(void)av;
	e = (t_env *)malloc(sizeof(t_env));
	parse_env(e, ep);
	prompt(e);
	while (get_next_line(0, &buf) != 0)
	{
		parse_cmd(e, buf);
		inspection(e);
	}
	return (0);
}
