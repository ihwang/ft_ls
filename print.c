/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:07:32 by tango             #+#    #+#             */
/*   Updated: 2020/02/14 20:50:13 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//working on this function!!!!!!!!!!!!!!
void		print(char **target, int nb, t_l *l)
{
	int i;

	i = -1;
	if (l)
		if (nb != l->nb)
			ft_strdel(&total);
	while (++i < nb)
	{
		ft_putstr(target[i]);
		ft_putchar('\n');
	}
	strlst_del(&target, nb);
}

void		clean_l(t_l *l)
{
	l->app_l = NULL;
	l->nb = 0;
	l->total = 0;
}

void		apply_print(char *opt, t_files *fs, char *dir, t_dirs *ds)
{
	t_l		l;

	clean_l(&l);
	if (opt)
	{
		dir && !ft_strchr(opt, 'a') ? a_del_invi(fs) : fs->nb;
		ft_strchr(opt, 't') ? t_sorting(fs) : fs->files;
		ft_strchr(opt, 'r') ? r_sorting(fs) : fs->files;
		ft_strchr(opt, 'l') ? l_add_info(fs, &l, dir) : fs->nb;
		ft_strchr(opt, 'l') ? print(l.app_l, l.nb) : print(fs->files, fs->nb);
	}
	else
	{
		dir ? a_del_invi(fs) : 0;
		print(fs->files, fs->nb);
	}
	ds->b = 1;
}

void		make_files(t_files *fs, char *dirs)
{
	DIR		*dirp;
	struct	dirent *dir;
	int		i;

	dirp = opendir(dirs);
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
		fs->files[i] = ft_strcat(fs->files[i], dir->d_name);
	}
	closedir(dirp);
	fs->files = lexi_sorting(fs->files, fs->nb);	
}

int			inc_depth(t_dirs *ds)
{
	ds->depth++;
	return (0);
}

int			shaping_dirs(char *dir, struct dirent *d, char *opt, t_dirs *ds)
{
	char	*dot;
	DIR		*dirp;

	dot = &dir[ft_strlen(dir)];
	ft_strcmp(dir, "/") ? ft_strcat(dir , "/") : 0;
	ft_strcat(dir, d->d_name);
	if (ft_strcmp(d->d_name, ".") == 0 || ft_strcmp(d->d_name, "..") == 0
		|| !(dirp = opendir(dir)))
	{
		*dot = '\0';
		return (1);
	}
	closedir(dirp);
	if (opt)
	{
		if (ft_strchr(opt, 'a'))
			return (inc_depth(ds));
		else if (d->d_name[0] != '.')
			return (inc_depth(ds));
	}
	else
		return (inc_depth(ds));
	*dot = '\0';
	return (1);
}

/*
** print_dir_name
*/

void		p_d_n(char *dir, t_dirs *ds)
{
	if (ds->re && !ds->depth && ds->nb_cp == 1)
		return ;
	if (ds->re)
	{
		if (ds->depth)
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

void		clean_ds_fs(t_dirs *ds, t_files *fs)
{
	int i;

	i = -1;
	if (fs)
	{
		fs->files = NULL;
		fs->nb = 0;
	}
	if (ds)
	{
		ds->dirs = NULL;
		ds->nb = 0;
		ds->nb_cp = 0;
		ds->is_no = 0;
		ds->b = 0;
		ds->re = 0;
		ds->depth = 0;
	}
}

void		dec_depth(char *dir, t_dirs *ds, char* opt)
{
	print_dirs(opt, ds);
	*(ft_strrchr(dir, '/')) = '\0';
	ds->depth--;
}

/*void		print_dirs(char *opt, t_dirs *ds)
{
	int		i;
	DIR		*dirp;
	struct	dirent *dir;
	t_files	fs;

	i = -1;
	while (++i < ds->nb)
	{
		clean_ds_fs(NULL, &fs);
		make_files(&fs, ds->dirs[i]);
		(ds->nb > 1 || ds->re || ds->b) ? p_d_n(ds->dirs[i], i, ds) : 0;
		apply_print(opt, &fs, ds->dirs[i]);
		if ((dirp = opendir(ds->dirs[i])) && ds->re)
		{
			while ((dir = readdir(dirp)))
			{
				if (!shaping_dirs(ds->dirs[i], dir, opt, ds))
					dec_depth(ds->dirs[i], ds, opt);
			}
			closedir(dirp);
			if (ds->depth)
				return ;
		}
	}
}
*/

void		cut_dir(t_dirs *ds)
{
	char	**temp;
	int		i;

	temp = (char**)malloc(sizeof(char*) * (ds->nb - 1));
	i = 0;
	while (++i < ds->nb)
	{
		temp[i - 1] = (char*)malloc(sizeof(char) * NAME_MAX);
		temp[i - 1] = ft_strcat(temp[i - 1], ds->dirs[i]);
	}
	strlst_del(&ds->dirs, ds->nb);
	ds->dirs = temp;
	ds->nb--;
}

void		print_dirs(char *opt, t_dirs *ds)
{
	DIR		*dirp;
	struct	dirent *dir;
	t_files	fs;

	while (0 < ds->nb)
	{
		clean_ds_fs(NULL, &fs);
		make_files(&fs, ds->dirs[0]);
		(ds->nb_cp > 1 || ds->re || ds->b) ? p_d_n(ds->dirs[0], ds) : 0;
		apply_print(opt, &fs, ds->dirs[0], ds);
		if ((dirp = opendir(ds->dirs[0])))
		{
			if (ds->re)
			{
				while ((dir = readdir(dirp)))
					if (!shaping_dirs(ds->dirs[0], dir, opt, ds))
						dec_depth(ds->dirs[0], ds, opt);
				if (ds->depth)
					return ;
			}
			closedir(dirp);
		}
		cut_dir(ds);
	}
}


void		ft_ls(char **paths, char *opt, int nb)
{
	t_dirs	ds;
	t_files	fs;

	clean_ds_fs(&ds, &fs);
	extract_files(&fs, paths, nb);
	extract_dirs(&ds, paths, nb);
	//while (1);
	(!fs.files && !ds.nb) ? no_dirs(&ds) : 0;
//	while (1);
	ds.nb_cp = ds.nb;
	if (fs.files)
	{
		apply_print(opt, &fs, NULL, &ds);
		ds.b = 1;
	}
	if (ds.dirs)
	{
		if (opt)
			ds.re = ft_strchr(opt, 'R') ? 1 : 0;
		print_dirs(opt, &ds);
	}
	//fs.files ? strlst_del(&fs.files, fs.nb) : 0;
	ds.dirs ? strlst_del(&ds.dirs, ds.nb) : 0;
	opt ? ft_strdel(&opt) : 0;
	while (1);
}
