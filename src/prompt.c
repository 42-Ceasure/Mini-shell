#include "shell.h"

void ft_cd(t_env *e)
{
	if (chdir(e->av[1]) != 0)
	{
		ft_putstr("c-sh : \"");
		ft_putstr(e->av[1]);
		ft_putendl("\" : exist only in your imagination");
	}
	// recalc_pwd(e);
	prompt(e);
}

void prompt(t_env *e)
{
	(void)e;
	// ft_putstr(*e->pwd);
	ft_putstr("c-sh# >> ");
}

void travaux(t_env *e)
{
	int i;
	pid_t father;
	DIR *dir;

	i = 0;
	father = fork();
	if (father > 0)
	{
		waitpid(father, NULL, 0);
		prompt(e);
	}
	if (father == 0)
	{
		while (e->paths[i])
		{
			if ((dir = opendir(ft_strjoin(e->paths[i], "/"))))
				if (!access(ft_strjoin(e->paths[i], ft_strjoin("/", e->av[0])), X_OK))
					execve(ft_strjoin(e->paths[i], ft_strjoin("/", e->av[0])), e->av, e->env);
			i++;
		}
		ft_putstr("c-sh : \'");
		ft_putstr(e->av[0]);
		ft_putendl("\' : command not found");
		exit(0);
	}
}

void inspection(t_env *e)
{
	if (e->av[0] == NULL)
		prompt(e);
	// if (!ft_strcmp(e->av[0], "exit"))
	// 	ft_exit();
	else if (!ft_strcmp(e->av[0], "env"))
		print_env(e);
	else if (!ft_strcmp(e->av[0], "print_vars"))
		print_vars(e);
	// if (!ft_strcmp(e->av[0], "setenv"))
	// 	ft_setenv();
	// if (!ft_strcmp(e->av[0], "unsetenv"))
	// 	ft_unsetenv();
	else if (!ft_strcmp(e->av[0], "cd"))
		ft_cd(e);
	else
		travaux(e);
}

void parse_cmd(t_env *e, char *buf)
{
	char *lol;

	lol = ft_epur_tabul(buf);
	e->av = ft_strsplit(lol, ' ');
}