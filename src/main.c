
#include "shell.h"

int main(int ac, char **av, char **ep)
{
	t_env	*e;
	char 	*buf;

	buf = NULL;
	if (ac == 1)
	{
		signal(SIGINT, handler);
		ft_swagg(av[0]);
		e = (t_env *)ft_memalloc(sizeof(t_env));
		parse_env(e, ep);
		prompt();
		while ((get_next_line(0, &buf) != 0))
		{
			if (buf[0] != '\0')
			{
				parse_cmd(e, buf);
				inspection(e);
				free(buf);
			}
			else
				free(buf);
			prompt();
		}
	}
	else
		ft_putendl("You ask me something strange...");
	return (0);
}
