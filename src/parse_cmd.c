
#include "shell.h"

void			parse_cmd(t_env *e, char *buf)
{
	size_t		i;
	size_t		j;
	size_t		k;

	int			pdes[2];
	pid_t		child;

	char		**tmp;
	char		**tmp2;
	char		*lol;

	i = 0;
	lol = ft_epur_tabul(buf);
	tmp = ft_strsplit(lol, ';');
	free(lol);
	while (tmp[i])
		i++;
	if (i != 1)
	{
		i = 0;
		while (tmp[i + 1])
		{
			j = 0;
			tmp2 = ft_strsplit(tmp[i], '|');
			k = 0;
			while (tmp2[k])
				k++;
			if (k != 1)
			{
				k--;
				child = fork();
				if (child == 0)
				{
					while (k > 0)
					{
						pipe(pdes);
						child = fork();
						if ((int)child > 0)
						{
							j = k;
							k = 0;
							dup2(pdes[0], STDIN_FILENO);
							close(pdes[1]);
							waitpid(child, NULL, 0);
						}
						if ((int)child == 0)
						{
							dup2(pdes[1], STDOUT_FILENO);
							close(pdes[0]);
							k--;
						}
					}
					memreg(e->av);
					e->av = ft_strsplit(tmp2[j], ' ');
					if (e->av[1])
						check_tild_minus(e, 1);
					inspection(e);
					exit(0);
				}
				if (child > 0)
				{
					e->mem = 0;
					waitpid(child, NULL, 0);
				}
			}
			else
			{
				memreg(e->av);
				e->av = ft_strsplit(tmp2[0], ' ');
				if (e->av[1])
					check_tild_minus(e, 1);
				inspection(e);
			}
			memreg(tmp2);
			i++;
		}
		j = 0;
		tmp2 = ft_strsplit(tmp[i], '|');
		i = 0;
		while (tmp2[i])
			i++;
		if (i != 1)
		{
			i--;
			child = fork();
			if (child == 0)
			{
				while (i > 0)
				{
					pipe(pdes);
					child = fork();
					if ((int)child > 0)
					{
						j = i;
						i = 0;
						dup2(pdes[0], STDIN_FILENO);
						close(pdes[1]);
						waitpid(child, NULL, 0);
					}
					if ((int)child == 0)
					{
						dup2(pdes[1], STDOUT_FILENO);
						close(pdes[0]);
						i--;
					}
				}
				memreg(e->av);
				e->av = ft_strsplit(tmp2[j], ' ');
				if (e->av[1])
					check_tild_minus(e, 1);
				inspection(e);
				exit(0);
			}
			if (child > 0)
			{
				e->mem = 0;
				waitpid(child, NULL, 0);
			}
		}
		else
		{
			e->mem = 2;
			memreg(e->av);
			e->av = ft_strsplit(tmp2[0], ' ');
			if (e->av[1])
				check_tild_minus(e, 1);
		}
		memreg(tmp2);
	}
	else
	{
		i = 0;
		j = 0;
		tmp2 = ft_strsplit(tmp[0], '|');
		while (tmp2[i])
			i++;
		if (i != 1)
		{
			i--;
			e->mem = 1;
			child = fork();
			if (child == 0)
			{
				while (i > 0)
				{
					pipe(pdes);
					child = fork();
					if ((int)child > 0)
					{
						j = i;
						i = 0;
						dup2(pdes[0], STDIN_FILENO);
						close(pdes[1]);
						waitpid(child, NULL, 0);
					}
					if ((int)child == 0)
					{
						dup2(pdes[1], STDOUT_FILENO);
						close(pdes[0]);
						e->mem = 0;
						i--;
					}
				}
				memreg(e->av);
				e->av = ft_strsplit(tmp2[j], ' ');
				if (e->av[1])
					check_tild_minus(e, 1);
				inspection(e);
				exit(0);
			}
			if (child > 0)
			{
				e->mem = 0;
				waitpid(child, NULL, 0);
			}
		}
		else
		{
			memreg(e->av);
			e->av = ft_strsplit(tmp2[0], ' ');
			if (e->av[1])
				check_tild_minus(e, 1);
		}
		memreg(tmp2);
	}
	memreg(tmp);
}
