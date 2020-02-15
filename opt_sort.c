/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:14 by tango             #+#    #+#             */
/*   Updated: 2020/02/06 20:08:54 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

long		get_m_time(char *file)
{
	struct stat sb;

	if (!(stat(file, &sb)))
		return (sb.st_mtimespec.tv_sec);
	else
		exit(1); //need to be fixed in usage_error
}

void		t_sorting(t_files *fs)
{
	int i;
	int j;
	char *temp;

	i = -1;
	while (++i < fs->nb)
	{
		j = -1;
		while (++j < fs->nb)
		{
			if (get_m_time(fs->files[i]) > get_m_time(fs->files[j]))
			{
				temp = fs->files[i];
				fs->files[i] = fs->files[j];
				fs->files[j] = temp;
			}
		}
	}
}
/*
char		**t_sorting(char **files, int nb)
{
	int i;
	int j;
	char *temp;

	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < nb)
		{
			if (get_m_time(files[i]) > get_m_time(files[j]))
			{
				temp = files[i];
				files[i] = files[j];
				files[j] = temp;
			}
		}
	}
	return (files);
}*/

char		**lexi_sorting(char **files, int nb)
{
	int i;
	int j;
	char *temp;

	i = -1;
	while (++i < nb)
	{
		j = -1;
		while (++j < nb)
		{
			if (ft_strcmp(files[i], files[j]) < 0)
			{
				temp = files[i];
				files[i] = files[j];
				files[j] = temp;
			}
		}
	}
	return (files);
}

void		r_sorting(t_files *fs)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = fs->nb - 1;
	while (i < fs->nb / 2)
	{
		temp = fs->files[i];
		fs->files[i] = fs->files[j];
		fs->files[j] = temp;
		i++;
		j--;
	}
}
/*
char		**r_sorting(char **files, int nb)
{
	int i;
	int j;
	char *temp;

	i = 0;	
	j = nb - 1;
	while (i < nb / 2)
	{
		temp = files[i];
		files[i] = files[j];
		files[j] = temp;
		i++;
		j--;
	}
	return (files);
}*/
