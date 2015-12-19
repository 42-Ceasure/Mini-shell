/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 06:35:42 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/18 11:49:45 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		re_usefull_vars(t_env *e)
{
	int		i;

	i = 0;
	while (e->env[i])
	{
		usefull_vars(e, i);
		i++;
	}
}

void		usefull_vars(t_env *e, size_t i)
{
	if (!ft_strncmp(e->env[i], "PWD=", 4))
		*g_pwd = &e->env[i][4];
	else if (!ft_strncmp(e->env[i], "OLDPWD=", 7))
		*g_oldpwd = &e->env[i][7];
	else if (!ft_strncmp(e->env[i], "HOME=", 5))
		*g_home = &e->env[i][5];
	else if (!ft_strncmp(e->env[i], "PATH=", 5))
	{
		memreg(g_paths);
		g_paths = ft_strsplit(&e->env[i][5], ':');
	}
}

void		init_null(t_env *e)
{
	e->env[0] = NULL;
	*g_pwd = NULL;
	*g_oldpwd = NULL;
	*g_home = NULL;
	ft_putstr("\n/!\\ Warning, you have no PATH");
	ft_putendl(" and no HOME var /!\\");
	ft_putendl("           (you have no ENV at all...)\n");
}

void		parse_env(t_env *e, char **ep)
{
	size_t	i;

	i = 0;
	while (ep[i] != NULL)
		i++;
	e->env = (char **)ft_memalloc(sizeof(char *) * i + 1);
	g_pwd = (char **)ft_memalloc(sizeof(char *));
	g_oldpwd = (char **)ft_memalloc(sizeof(char *));
	g_home = (char **)ft_memalloc(sizeof(char *));
	g_paths = NULL;
	if (i != 0)
	{
		i = 0;
		while (ep[i])
		{
			e->env[i] = ft_strdup(ep[i]);
			usefull_vars(e, i);
			i++;
		}
	}
	else
		init_null(e);
}
