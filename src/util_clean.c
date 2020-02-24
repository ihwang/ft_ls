/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:42:42 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 16:08:42 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		clean_ds_fs(t_dirs *ds, t_files *fs, unsigned long opt)
{
	int i;

	i = -1;
	if (fs)
	{
		fs->files = NULL;
		fs->nb = 0;
		fs->opt = opt;
	}
	if (ds)
	{
		ds->dirs = NULL;
		ds->nb = 0;
		ds->nb_cp = 0;
		ds->b = 0;
		ds->re = 0;
		ds->depth = 0;
		ds->opt = opt;
	}
}

void		clean_l(t_l *l, unsigned long opt)
{
	l->app_l = NULL;
	l->nb = 0;
	l->total = 0;
	l->opt = opt;
}

void		clean_lens(t_len *lens, t_files *fs)
{
	lens->perm = LEN_PERM;
	lens->link = 0;
	lens->uid = 0;
	lens->gid = 0;
	lens->size = 0;
	lens->date = LEN_DATE;
	lens->fname = 0;
	lens->sym = 0;
	lens->minor = 0;
	lens->major = 0;
	lens->is_d = 0;
	lens->sum = 0;
	lens->opt = fs->opt;
}
