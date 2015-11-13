#include "shell.h"

void ft_prompt(t_env *e)
{
	char 	*buf;
	pid_t	father;

	ft_putstr("#> ");
	while (get_next_line(0, &buf) != 0)
	{
		father = fork();
		if (father > 0)
		{
			waitpid(father, NULL, 0);
			ft_putstr("#> ");
		}
		if (father == 0)
		{
			sleep(1);
			execve(buf, e->av, NULL);
		}
	}
}