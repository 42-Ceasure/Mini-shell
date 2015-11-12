
#include "shell.h"

int main(int ac, char **av, char **ep)
{
	(void)ac;
	(void)av;
	char **env;

	env = parse_env(ep);
	ft_prompt(env);

	return (0);
}
