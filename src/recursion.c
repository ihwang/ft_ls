/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:44:50 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 16:05:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		cut_file(t_files *d)
{
	char	**temp;
	int		i;

	temp = (char**)malloc(sizeof(char*) * (d->nb - 1));
	i = 0;
	while (++i < d->nb)
		temp[i - 1] = d->files[i];
	strlst_del(&d->files, 1);
	d->files = temp;
	d->nb--;
}

void		dec_depth(char *dir, t_dirs *ds, unsigned long opt)
{
	char	*dot;

	print_dirs(opt, ds);
	dot = ft_strrchr(dir, '/');
	if (dot != &dir[0])
		*dot = '\0';
	else
		dir[1] = '\0';
	ds->depth--;
}

int			shaping_dirs(char *dir, char *d, unsigned long opt,
		t_dirs *ds)
{
	char	*dot;

	dot = &dir[ft_strlen(dir)];
	if (!(dir[0] == '/' && dir[1] == '\0') && dir[ft_strlen(dir) - 1] != '/')
		ft_strcat(dir, "/");
	ft_strcat(dir, d);
	if (ft_strcmp(d, ".") == 0 || ft_strcmp(d, "..") == 0
		|| !check_dir(dir))
	{
		*dot = '\0';
		return (1);
	}
	if (opt & L_A)
	{
		ds->depth++;
		return (0);
	}
	else if (d[0] != '.')
	{
		ds->depth++;
		return (0);
	}
	*dot = '\0';
	return (1);
}
