
#include "shell.h"

void			parse_cmd(t_env *e, char *buf)
{
	size_t		i;
	char		**tmp;
	char		*lol;

	i = 0;
	lol = ft_epur_tabul(buf);
	tmp = ft_strsplit(lol, ';');
	free(lol);
	while (tmp[i])
		i++;
	if (i == 1)
	{
		memreg(e->av);
		e->av = ft_strsplit(tmp[0], ' ');
		if (e->av[1])
			check_tild_minus(e, 1);
	}
	else
	{
		i = 0;
		while (tmp[i + 1])
		{
			memreg(e->av);
			e->av = ft_strsplit(tmp[i], ' ');
			if (e->av[1])
				check_tild_minus(e, 1);
			inspection(e);
			i++;
		}
		memreg(e->av);
		e->av = ft_strsplit(tmp[i], ' ');
		if (e->av[1])
			check_tild_minus(e, 1);
	}
	memreg(tmp);
}
