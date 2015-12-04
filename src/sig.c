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
	prompt();
}
