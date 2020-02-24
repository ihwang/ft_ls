/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:15:17 by tango             #+#    #+#             */
/*   Updated: 2020/02/22 22:25:19 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		apply_print(unsigned long opt, t_files *fs, char *dir,
		t_dirs *ds)
{
	t_l		l;

	perm_check(dir, ds);
	clean_l(&l, opt);
	(dir && !(opt & L_A)) ? a_del_invi(fs) : 0;
	opt & L_T ? t_sorting(fs, dir) : 0;
	opt & L_R ? r_sorting(fs) : 0;
	opt & L_L ? l_add_info(fs, &l, dir) : 0;
	opt & L_L ? print(l.app_l, l.nb) : print(fs->files, fs->nb);
	strlst_del(&l.app_l, l.nb);
	ds->b = 1;
}

static void		make_files(t_files *fs, char *dirs)
{
	DIR			*dirp;
	t_dirent	*dir;
	int			i;

	if (!(dirp = opendir(dirs)))
		return ;
	while ((dir = readdir(dirp)))
		fs->nb++;
	closedir(dirp);
	fs->files = (char**)malloc(sizeof(char*) * fs->nb);
	dirp = opendir(dirs);
	i = -1;
	while (++i < fs->nb)
	{
		dir = readdir(dirp);
		fs->files[i] = (char*)malloc(sizeof(char) * NAME_MAX);
		ft_strncat(fs->files[i], dir->d_name, ft_strlen(dir->d_name));
	}
	closedir(dirp);
	fs->files = lexi_sorting(fs->files, fs->nb);
}

static void		cut_dir(t_dirs *ds)
{
	char		**temp;
	int			i;

	temp = (char**)malloc(sizeof(char*) * (ds->nb - 1));
	i = 0;
	while (++i < ds->nb)
		temp[i - 1] = ds->dirs[i];
	strlst_del(&ds->dirs, 1);
	ds->dirs = temp;
	ds->nb--;
}

void			print_dirs(unsigned long opt, t_dirs *ds)
{
	t_files		fs;

	while (ds->nb)
	{
		clean_ds_fs(NULL, &fs, opt);
		make_files(&fs, ds->dirs[0]);
		(ds->nb_cp > 1 || ds->re || ds->b) ? p_d_n(ds->dirs[0], ds) : 0;
		apply_print(opt, &fs, ds->dirs[0], ds);
		if (ds->re)
		{
			while (fs.nb)
			{
				if (!shaping_dirs(ds->dirs[0], fs.files[0], opt, ds))
					dec_depth(ds->dirs[0], ds, opt);
				cut_file(&fs);
			}
			if (ds->depth)
				return (strlst_del(&fs.files, fs.nb));
		}
		cut_dir(ds);
		strlst_del(&fs.files, fs.nb);
	}
}

void			ft_ls(char **paths, unsigned long opt, int nb)
{
	t_dirs		ds;
	t_files		fs;

	clean_ds_fs(&ds, &fs, opt);
	extract_files(&fs, paths, nb);
	extract_dirs(&ds, paths, nb);
	(!fs.files && !ds.nb) ? no_dirs(&ds) : 0;
	ds.nb_cp = ds.nb;
	if (fs.files)
	{
		apply_print(opt, &fs, NULL, &ds);
		ds.b = 1;
	}
	if (ds.dirs)
	{
		ds.re = opt & U_R ? 1 : 0;
		print_dirs(opt, &ds);
	}
	fs.files ? strlst_del(&fs.files, fs.nb) : 0;
	ds.dirs ? strlst_del(&ds.dirs, ds.nb) : 0;
}
