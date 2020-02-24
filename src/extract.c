/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:46:02 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/20 19:00:53 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int			check_dir(char *path)
{
	t_stat	sb;

	lstat(path, &sb);
	if ((sb.st_mode & S_IFDIR) == S_IFDIR)
		return (1);
	else
		return (0);
}

void		extract_dirs(t_dirs *ds, char **paths, int nb)
{
	int		i;
	int		j;

	i = -1;
	while (++i < nb)
		if (check_dir(paths[i]))
			ds->nb++;
	if (ds->nb == 0)
		return ;
	ds->dirs = (char**)malloc(sizeof(char*) * ds->nb);
	i = -1;
	j = -1;
	while (++i < nb)
		if (check_dir(paths[i]))
		{
			if (ft_strlen(paths[i]) > NAME_MAX)
				usage_error(paths[i]);
			ds->dirs[++j] = (char*)malloc(sizeof(char) * PATH_MAX);
			ds->dirs[j][0] = '\0';
			ds->dirs[j] = ft_strcat(ds->dirs[j], paths[i]);
		}
}

void		extract_files(t_files *fs, char **paths, int nb)
{
	int		i;
	int		j;

	i = -1;
	while (++i < nb)
		if (!check_dir(paths[i]))
			fs->nb++;
	if (fs->nb == 0)
		return ;
	fs->files = (char**)malloc(sizeof(char*) * fs->nb);
	i = -1;
	j = -1;
	while (++i < nb)
		if (!check_dir(paths[i]))
		{
			if (ft_strlen(paths[i]) > NAME_MAX)
				usage_error(paths[i]);
			fs->files[++j] = (char*)malloc(NAME_MAX);
			fs->files[j][0] = '\0';
			fs->files[j] = ft_strcat(fs->files[j], paths[i]);
		}
}
