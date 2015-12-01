#include "shell.h"

void		change_dir(t_env *e, char *s)
{
	char	*cwd;
	char	pwd[PATH_MAX + 1];

	if (chdir(s) == 0)
	{
		modif_env(e, "OLDPWD", *e->pwd);
		cwd = getcwd(pwd, PATH_MAX + 1);
		if (cwd != NULL)
			modif_env(e, "PWD", pwd);
	}
	else
	{
		ft_putstr("c-sh : \"");
		ft_putstr(e->av[1]);
		ft_putendl("\" : exist only in your imagination");
	}
}

void		ft_cd(t_env *e)
{
	char	*lol;
	char	*tmp;

	lol = NULL;
	tmp = NULL;
	if (e->av[1] == NULL || !ft_strcmp(e->av[1], "~"))
		change_dir(e, *e->home);
	else if (!strncmp(e->av[1], "~/", 2))
	{
		tmp = ft_strsub(e->av[1], 1, (ft_strlen(e->av[1]) - 1));
		lol = ft_strjoin(*e->home, tmp);
		change_dir(e, lol);
		free(tmp);
		free(lol);
	}
	else if (!strcmp(e->av[1], "-"))
		change_dir(e, *e->oldpwd);
	else
		change_dir(e, e->av[1]);
	prompt(e);
}

void prompt(t_env *e)
{
	(void)e;
	ft_putstr("\e[1m\e[38;5;42m");
	ft_putstr(*e->pwd);
	ft_putstr("\e[38;5;124m");
	ft_putstr(" c-sh #>> \e[0m");
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
		if (e->paths)
		{	
			while (e->paths[i])
			{
				if ((dir = opendir(ft_strjoin(e->paths[i], "/"))))
				{
					if (!access(e->av[0], X_OK))
						execve(e->av[0], e->av, e->env);
					if (!access(ft_strjoin(e->paths[i], ft_strjoin("/", e->av[0])), X_OK))
						execve(ft_strjoin(e->paths[i], ft_strjoin("/", e->av[0])), e->av, e->env);
					closedir(dir);
				}
				i++;
			}
			ft_putstr("c-sh : \'");
			ft_putstr(e->av[0]);
			ft_putendl("\' : command not found");
			exit(0);
		}
		else
		{
			ft_putstr("c-sh : \'");
			ft_putstr(e->av[0]);
			ft_putendl("\' : command not found");
			exit(0);	
		}
	}
}

void inspection(t_env *e)
{
	if (e->av[0] == NULL)
		prompt(e);
	else if (!ft_strcmp(e->av[0], "exit"))
		exit(0);
	else if (!ft_strcmp(e->av[0], "env"))
		print_env(e);
	else if (!ft_strcmp(e->av[0], "print_vars"))
		print_vars(e);
	else if (!ft_strcmp(e->av[0], "setenv"))
		ft_setenv(e);
	else if (!ft_strcmp(e->av[0], "unsetenv"))
		ft_unsetenv(e);
	else if (!ft_strcmp(e->av[0], "cd"))
		ft_cd(e);
	else
		travaux(e);
}

void parse_cmd(t_env *e, char *buf)
{
	memreg(e->av);
	e->av = ft_strsplit(buf, ' ');
}