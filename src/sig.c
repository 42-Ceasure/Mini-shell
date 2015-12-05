
#include "shell.h"

void handler(int sig)
{
	(void)sig;
	ft_putchar('\n');
	prompt();
}
