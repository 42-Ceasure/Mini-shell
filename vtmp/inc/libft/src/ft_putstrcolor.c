/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:45:30 by cglavieu          #+#    #+#             */
/*   Updated: 2015/12/19 17:09:50 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrcolor(char *col, char *str, char *end)
{
	char	*dst;

	dst = (char *)ft_memalloc(ft_strlen(col) + ft_strlen(str) + ft_strlen(end));
	ft_strcpy(dst, col);
	ft_strcat(dst, str);
	ft_strcat(dst, end);
	ft_putstr(dst);
	free(dst);
}
