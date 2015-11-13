
#include "shell.h"

int main(int ac, char **av, char **ep)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	parse_env(e, ac, av, ep);
	ft_prompt(e);

	return (0);
}
