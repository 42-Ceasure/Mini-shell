/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:42:26 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/19 17:24:30 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		prompt(void)
{
	if (g_pwd)
	{
		ft_putstr("\x1b[1m\x1b[38;5;42m");
		ft_putstr(*g_pwd);
	}
	ft_putstr("\x1b[38;5;124m");
	ft_putstr(" c-sh #>> ");
	ft_putstr("\x1b[0m");
}

int			main(int ac, char **av, char **ep)
{
	t_env	*e;
	char	*buf;

	buf = NULL;
	g_mem = 0;
	if (ac == 1 && av != NULL)
	{
		e = (t_env *)ft_memalloc(sizeof(t_env));
		signal(SIGINT, handler);
		parse_env(e, ep);
		prompt();
		while ((get_next_line(0, &buf) != 0))
		{
			if (buf[0] != '\0')
				parse_cmd(e, buf);
			free(buf);
			if (g_mem != 1)
				prompt();
			g_mem = 0;
		}
	}
	else
		ft_putendl("You ask me something strange...");
	return (0);
}
