
#include "shell.h"

void ft_swagg(char *s)
{
		ft_putstr("launching ");
		ft_putendl(s);
		// usleep(500000);
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putendl(";-.               ,");
		// usleep(500000);
		ft_putendl(" \\ '.           .'/");
		// usleep(500000);
		ft_putendl("  \\  \\ .---. .-' /");
		// usleep(500000);
		ft_putendl("   '. '     `\\_.'");
		// usleep(500000);
		ft_putstr("     |(),()  |     ");
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putendl(",");
		ft_putstr("\e[1m\e[38;5;166m");
		// usleep(500000);
		ft_putstr("     (  __   /   ");
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putendl(".' \\");
		// usleep(500000);	
		ft_putstr("    .'");
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putstr("'.___.'");
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putstr("--,");
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putstr("/");
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putendl("\\_,|");
		// usleep(500000);
		ft_putstr("   {  /     \\   }   ");
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putendl("|");
		// usleep(500000);
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putstr("    '.\\     /_.'    ");
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putendl("/");
		// usleep(500000);
		ft_putstr("      \\");
		ft_putstr("\e[1m\e[38;5;186m");
		ft_putstr("'-.-'");
		ft_putstr("\e[1m\e[38;5;166m");
		ft_putendl("/ `; _.'");
		// usleep(500000);
		ft_putendl("       | | |  /");
		// usleep(500000);
		ft_putendl("      `\"\"'\"`\"\"`");
		// usleep(500000);
		ft_putendl("\e[0m");
}

void handler(int sig)
{
	(void)sig;
	ft_putchar('\n');
}

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
		prompt(e);
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
			prompt(e);
		}
	}
	else
		ft_putendl("You ask me something strange...");
	return (0);
}
