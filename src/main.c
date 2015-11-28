
#include "shell.h"

void ft_swagg(char *s)
{
		ft_putstr("launching ");
		ft_putendl(s);
		usleep(500000);
		ft_putendl(";-.               ,");
		usleep(500000);
		ft_putendl(" \\ '.           .'/");
		usleep(500000);
		ft_putendl("  \\  \\ .---. .-' /");
		usleep(500000);
		ft_putendl("   '. '     `\\_.'");
		usleep(500000);
		ft_putendl("     |(),()  |     ,");
		usleep(500000);
		ft_putendl("     (  __   /   .' \\");
		usleep(500000);	
		ft_putendl("    .''.___.'--,/\\_,|");
		usleep(500000);
		ft_putendl("   {  /     \\   }   |");
		usleep(500000);
		ft_putendl("    '.\\     /_.'    /");
		usleep(500000);
		ft_putendl("     |'-.-',  `; _.'");
		usleep(500000);
		ft_putendl("     |  |  |   |`");
		usleep(500000);
		ft_putendl("     `\"\"`\"\"`\"\"\"`");
		usleep(500000);
		ft_putchar('\n');
}

int main(int ac, char **av, char **ep)
{
	t_env	*e;
	char 	*buf;

	(void)av;
	if (ac == 1)
	{
		ft_swagg(av[0]);
		e = (t_env *)malloc(sizeof(t_env));
		parse_env(e, ep);
		prompt(e);
		while (get_next_line(0, &buf) != 0)
		{
			parse_cmd(e, buf);
			inspection(e);
			memreg(e, buf);
		}
	}
	else
		ft_putendl("You ask me something strange...");
	return (0);
}
