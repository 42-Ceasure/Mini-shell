#include "shell.h"

void	swagg_three(void)
{
	ft_putendl("       | | |  /");
	usleep(50000);
	ft_putendl("      `\"\"'\"`\"\"`");
	ft_putendl("\e[0m");
	sleep(1);
}

void	swagg_two(void)
{
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putstr("'.___.'");
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putstr("--,");
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putstr("/");
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putendl("\\_,|");
	usleep(50000);
	ft_putstr("   {  /     \\   }   ");
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putendl("|");
	usleep(50000);
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putstr("    '.\\     /_.'    ");
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putendl("/");
	usleep(50000);
	ft_putstr("      \\");
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putstr("'-.-'");
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putendl("/ `; _.'");
	usleep(50000);
	swagg_three();
}

void ft_swagg(char *s)
{
	ft_putstr("launching ");
	ft_putendl(s);
	sleep(1);
	ft_putchar('\n');
	sleep(1);
	ft_putstr("\e[1m\e[38;5;166m");
	ft_putendl(";-.               ,");
	usleep(50000);
	ft_putendl(" \\ '.           .'/");
	usleep(50000);
	ft_putendl("  \\  \\ .---. .-' /");
	usleep(50000);
	ft_putendl("   '. '     `\\_.'");
	usleep(50000);
	ft_putstr("     |(),()  |     ");
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putendl(",");
	ft_putstr("\e[1m\e[38;5;166m");
	usleep(50000);
	ft_putstr("     (  __   /   ");
	ft_putstr("\e[1m\e[38;5;186m");
	ft_putendl(".' \\");
	usleep(50000);	
	ft_putstr("    .'");
	swagg_two();
}
