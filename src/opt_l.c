/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:59 by tango             #+#    #+#             */
/*   Updated: 2020/02/21 23:04:47 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			add_total(t_l *l, t_len len)
{
	unsigned long	i;
	char			*total;

	i = -1;
	while (++i < len.sum)
		l->app_l[0][i] = '\0';
	if (l->nb)
	{
		total = ft_itoa(l->total);
		l->app_l[0] = ft_strcat(l->app_l[0], "total ");
		l->app_l[0] = ft_strcat(l->app_l[0], total);
		ft_strdel(&total);
	}
}

static void			dir_mm(t_files *fs, t_len *lens, t_l *l, char *dir)
{
	int				max;
	int				i;

	i = -1;
	max = 0;
	l->app_l = (char**)malloc(sizeof(char*) * (l->nb + 1));
	while (++i < l->nb)
	{
		max = measure_l(fs->files[i], dir, max, lens);
		if (lens->is_d)
		{
			lens->is_d = 0;
			l->nb--;
		}
	}
	i = -1;
	max += 1;
	l->nb = l->nb ? l->nb + 1 : 0;
	while (++i < l->nb)
		l->app_l[i] = (char*)malloc(sizeof(char) * max);
	l->nb = l->nb ? l->nb - 1 : 0;
}

static void			file_mm(t_files *fs, t_len *lens, t_l *l)
{
	int				max;
	int				i;

	i = -1;
	max = 0;
	l->app_l = (char**)malloc(sizeof(char*) * (l->nb));
	while (++i < l->nb)
		max = measure_l(fs->files[i], NULL, max, lens);
	max += 1;
	i = -1;
	while (++i < l->nb)
		l->app_l[i] = (char*)malloc(sizeof(char) * max);
}

void				l_add_info(t_files *fs, t_l *l, char *dir)
{
	int				i;
	t_len			lens;

	clean_lens(&lens, fs);
	l->nb = fs->nb;
	if (dir)
	{
		if (!l->nb)
			return (strlst_del(&fs->files, fs->nb));
		dir_mm(fs, &lens, l, dir);
	}
	else
		file_mm(fs, &lens, l);
	i = -1;
	while (++i < l->nb)
		l->total += dir ? make_lines1(fs->files[i], dir, l->app_l[i + 1], lens)
			: make_lines1(fs->files[i], dir, l->app_l[i], lens);
	(dir && !lens.is_d) ? add_total(l, lens) : 0;
	l->nb = (dir && l->nb) ? l->nb + 1 : l->nb;
}
