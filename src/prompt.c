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
	if (e->av[1] == NULL)
		change_dir(e, *e->home);
	else
		change_dir(e, e->av[1]);
}

int prompt(t_env *e)
{
	(void)e;
	ft_putstr("\e[1m\e[38;5;42m");
	ft_putstr(*e->pwd);
	ft_putstr("\e[38;5;124m");
	ft_putstr(" c-sh #>> \e[0m");
	return (1);
}

void travaux(t_env *e)
{
	int i;
	pid_t father;
	DIR *dir;

	i = 0;
	father = fork();
	if (father > 0)
		waitpid(father, NULL, 0);
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

void check_tild_minus(t_env *e, size_t z)
{
	size_t	i;
	char	*tmp;
	char 	*lol;

	tmp = NULL;
	lol = NULL;
	i = ft_strlen(e->av[z]);
	if (i == 1 && !strncmp(e->av[z], "~", 1))
	{
		free(e->av[z]);
		e->av[z] = ft_strdup(*e->home);
	}
	else if (i > 1 && !strncmp(e->av[z], "~/", 2))
	{
			tmp = ft_strsub(e->av[z], 1, (ft_strlen(e->av[z]) - 1));
			lol = ft_strjoin(*e->home, tmp);
			free(e->av[z]);
			e->av[z] = ft_strdup(lol);
			free(tmp);
			free(lol);
	}
	else if (i == 1 && !strncmp(e->av[z], "-", 1))
	{
		free(e->av[z]);
		e->av[z] = ft_strdup(*e->oldpwd);
	}
	else if (i > 1 && !strncmp(e->av[z], "-/", 2))
	{
			tmp = ft_strsub(e->av[z], 1, (ft_strlen(e->av[z]) - 1));
			lol = ft_strjoin(*e->oldpwd, tmp);
			free(e->av[z]);	
			e->av[z] = ft_strdup(lol);
			free(tmp);
			free(lol);
	}
}

void inspection(t_env *e)
{
	if (!ft_strcmp(e->av[0], "exit"))
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
	else if (!ft_strncmp(e->av[0], "~", 1) || !ft_strncmp(e->av[0], "-", 1))
	{
		check_tild_minus(e, 0);
		change_dir(e, e->av[0]);
	}
	else
		travaux(e);
}

void parse_cmd(t_env *e, char *buf)
{
	memreg(e->av);
	e->av = ft_strsplit(buf, ' ');
	if (e->av[1])
		check_tild_minus(e, 1);
}