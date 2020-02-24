/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:42:29 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/20 21:47:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

/*
** print_dir_name
*/

void		p_d_n(char *dir, t_dirs *ds)
{
	if (ds->re && !ds->depth && ds->nb_cp == 1)
		return ;
	if (ds->re)
	{
		if (ds->depth || ds->b)
			ft_putstr("\n");
		ft_putstr(dir);
		ft_putstr(":\n");
	}
	else if (ds->nb_cp > 1 || ds->b)
	{
		if (ds->b)
		{
			ft_putstr("\n");
			ft_putstr(dir);
			ft_putstr(":\n");
		}
		else
		{
			ft_putstr(dir);
			ft_putstr(":\n");
		}
	}
}

void		print(char **target, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
	{
		ft_putstr(target[i]);
		ft_putchar('\n');
	}
}

void		init_dirp(DIR **dirp)
{
	closedir(*dirp);
	*dirp = NULL;
}

void		ds_del(char **dirs, int nb)
{
	while (0 <= --nb)
		ft_strdel(&(dirs[nb]));
	free(dirs);
}

void		strlst_del(char ***target, int nb)
{
	while (0 <= --nb)
		ft_strdel(&(target[0][nb]));
	free(*target);
	*target = NULL;
}
