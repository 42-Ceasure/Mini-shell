/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 06:35:42 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/18 11:51:20 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		change_dir(t_env *e, char *s)
{
	char	*cwd;
	char	pwd[PATH_MAX + 1];
	char	npwd[PATH_MAX + 1];

	cwd = getcwd(pwd, PATH_MAX + 1);
	if (chdir(s) == 0)
	{
		if (cwd != NULL)
			modif_env(e, "OLDPWD", pwd);
		cwd = getcwd(npwd, PATH_MAX + 1);
		if (cwd != NULL)
			modif_env(e, "PWD", npwd);
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
	{
		if (*g_home)
			change_dir(e, *g_home);
		else
			ft_putendl("no home directory");
	}
	else
		change_dir(e, e->av[1]);
}
