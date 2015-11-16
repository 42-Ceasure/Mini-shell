
#include "shell.h"

int main(int ac, char **av, char **ep)
{
	t_env *e;
	char 	*buf;
	pid_t	father;

	e = (t_env *)malloc(sizeof(t_env));
	parse_env(e, ep);
	print_env(e);
	printf("\n\n");
	print_vars(e);
	ft_putstr("#> ");
	while (get_next_line(0, &buf) != 0)
	{
		parse_cmd(e, ac, av, ep, buf);
		father = fork();
		if (father > 0)
		{
			waitpid(father, NULL, 0);
			ft_putstr("#> ");
		}
		if (father == 0)
		{
			sleep(1);
			execve(e->av[0], e->av, NULL);
		}
	}
	return (0);
}
