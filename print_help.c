/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:18:16 by tango             #+#    #+#             */
/*   Updated: 2020/02/14 20:29:00 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ds_del(char **dirs, int nb)
{
	while (0 <= --nb)
		ft_strdel(&(dirs[nb]));
	free(dirs);
}

void	strlst_del(char ***target, int nb)
{
	while (0 <= --nb)
		ft_strdel(&(target[0][nb]));
	free(*target);
	*target = NULL;
	//need to be fixed later
}

void	no_dirs(t_dirs *ds)
{
	ds->dirs = (char**)malloc(sizeof(char*) * 1);
	ds->dirs[0] = (char*)malloc(sizeof(char) * PATH_MAX);
	ds->dirs[0] = ft_strcat(ds->dirs[0], ".");
	ds->nb = 1;
}

void			extract_dirs(t_dirs *ds, char **paths, int nb)
{
	int 		i;
	int 		j;
	DIR			*dirp;

	i = -1;
	while (++i < nb)
		if ((dirp = opendir(paths[i])))
		{
			closedir(dirp);
			ds->nb++;
		}
	if (ds->nb == 0)
		return ;
	ds->dirs = (char**)malloc(sizeof(char*) * ds->nb);
	i = -1;
	j = -1;
	while (++i < nb)
		if ((dirp = opendir(paths[i])))
		{
			if (ft_strlen(paths[i]) > NAME_MAX)
				usage_error(paths[i]);
			ds->dirs[++j] = (char*)malloc(sizeof(char) * PATH_MAX);
			ds->dirs[j] = ft_strcat(ds->dirs[j], paths[i]);
			closedir(dirp);
		}
	//while (1);
}

void			extract_files(t_files *fs, char **paths, int nb)
{
	int			i;
	int			j;
	DIR			*dirp;

	i = -1;
	while (++i < nb)
	{
		if (!(dirp = opendir(paths[i])))
			fs->nb++;
		else
			closedir(dirp);
	}	
	if (fs->nb == 0)
		return ;
	fs->files = (char**)malloc(sizeof(char*) * fs->nb);
	i = -1;
	j = -1;
	while (++i < nb)
		if (!opendir(paths[i]))
		{
			if (ft_strlen(paths[i]) > NAME_MAX)
				usage_error(paths[i]);
			fs->files[++j] = (char*)malloc(NAME_MAX);
			fs->files[j] = ft_strcat(fs->files[j], paths[i]);
		}
}
