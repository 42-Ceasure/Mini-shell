/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 06:35:42 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/19 17:38:34 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		endit(char *s)
{
	ft_putstr("c-sh : \'");
	ft_putstr(s);
	ft_putendl("\' : command not found");
	exit(0);
}

void		execution(t_env *e)
{
	int		i;
	DIR		*dir;

	i = 0;
	while (g_paths[i])
	{
		if ((dir = opendir(ft_strjoin(g_paths[i], "/"))))
		{
			if (!access(ft_strjoin(g_paths[i],
				ft_strjoin("/", e->av[0])), X_OK))
				execve(ft_strjoin(g_paths[i],
					ft_strjoin("/", e->av[0])), e->av, e->env);
			closedir(dir);
		}
		i++;
	}
}

void		chk_n_ex_cmd(t_env *e)
{
	pid_t	father;

	father = fork();
	if (father > 0)
		waitpid(father, NULL, 0);
	if (father == 0)
	{
		if (!access(e->av[0], X_OK))
			execve(e->av[0], e->av, e->env);
		if (g_paths)
		{
			execution(e);
			endit(e->av[0]);
		}
		else
			endit(e->av[0]);
	}
}

void		inspection(t_env *e)
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
		chk_n_ex_cmd(e);
}
