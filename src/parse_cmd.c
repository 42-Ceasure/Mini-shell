
#include "shell.h"

void			set_av(t_env *e)
{
	memreg(e->av);
	e->av = ft_strsplit(e->tmp2[e->j], ' ');
	if (e->av[1])
		check_tild_minus(e, 1);
	inspection(e);
}

void			do_it_son(t_env *e, pid_t child)
{
	int			pdes[2];

	while (e->k > 0)
	{
		pipe(pdes);
		child = fork();
		if ((int)child > 0)
		{
			e->j = e->k;
			e->k = 0;
			dup2(pdes[0], STDIN_FILENO);
			close(pdes[1]);
			waitpid(child, NULL, 0);
		}
		if ((int)child == 0)
		{
			dup2(pdes[1], STDOUT_FILENO);
			close(pdes[0]);
			e->k--;
		}
	}
	set_av(e);
	exit(0);
}

void			chk_pipe(t_env *e, char **tmp)
{
	pid_t		child;

	e->j = 0;
	e->k = 0;
	e->tmp2 = ft_strsplit(tmp[e->i], '|');
	while (e->tmp2[e->k])
		e->k++;
	if (e->k != 1)
	{
		e->k--;
		child = fork();
		if (child == 0)
			do_it_son(e, child);
		if (child > 0)
			waitpid(child, NULL, 0);
	}
	else
		set_av(e);
	memreg(e->tmp2);
}

void			parse_cmd(t_env *e, char *buf)
{
	char		**tmp;
	char		*lol;

	e->i = 0;
	lol = ft_epur_tabul(buf);
	tmp = ft_strsplit(lol, ';');
	free(lol);
	while (tmp[e->i])
		e->i++;
	if (e->i != 1)
	{
		e->i = 0;
		while (tmp[e->i + 1])
		{
			chk_pipe(e, tmp);
			e->i++;
		}
		chk_pipe(e, tmp);
	}
	else
	{
		e->i = 0;
		chk_pipe(e, tmp);
	}
	memreg(tmp);
}
