/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:49:43 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 19:07:39 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				itox_clean(char *line, int nb, char *(itox)(int))
{
	char			*ascii;

	ascii = itox(nb);
	ft_strcat(line, ascii);
	ft_strdel(&ascii);
}

int					get_sb(char *file, char *dir, t_stat *sb, char **dot)
{
	*dot = &(dir[ft_strlen(dir)]);
	dir = ft_strcat(dir, "/");
	dir = ft_strcat(dir, file);
	if (lstat(dir, sb))
	{
		errno = 0;
		**dot = '\0';
		return (1);
	}
	**dot = '\0';
	return (0);
}

char				*mk_w(unsigned long big, unsigned long small)
{
	unsigned long	i;
	char			*white;

	white = (char*)malloc(big - small + 1);
	i = 0;
	while (i < big - small)
		white[i++] = ' ';
	white[i] = '\0';
	free(white);
	return (white);
}

void				no_dirs(t_dirs *ds)
{
	ds->dirs = (char**)malloc(sizeof(char*) * 1);
	ds->dirs[0] = (char*)malloc(sizeof(char) * PATH_MAX);
	ds->dirs[0] = ft_strcat(ds->dirs[0], ".");
	ds->nb = 1;
}
