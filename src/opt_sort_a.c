/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_sort_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:14 by tango             #+#    #+#             */
/*   Updated: 2020/02/23 21:13:18 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
/*void		t_sorting(t_files *fs, char *dir)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < fs->nb)
	{
		j = -1;
		while (++j < fs->nb - 1)
		{
			if (get_time(fs->files[j], dir, fs->opt) <
					get_time(fs->files[j + 1], dir, fs->opt))
			{
				temp = fs->files[j];
				fs->files[j] = fs->files[j + 1];
				fs->files[j + 1] = temp;
			}
		}
	}
}*/

void		t_sorting(t_files *fs, char *dir)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (++i < fs->nb)
	{
		j = -1;
		while (++j < fs->nb - 1)
		{
			if (get_time(fs->files[j], dir, fs->opt) <
					get_time(fs->files[j + 1], dir, fs->opt))
			{
				temp = fs->files[j];
				fs->files[j] = fs->files[j + 1];
				fs->files[j + 1] = temp;
			}
		}
	}
}

char		**lexi_sorting(char **files, int nb)
{
	int		i;
	int		j;
	char	*temp;

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

void		a_del_invi(t_files *fs)
{
	int		i;
	int		len;
	int		len_cp;
	char	**temp;

	len = -1;
	while (++len < fs->nb)
		if (fs->files[len][0] != '.')
			break ;
	temp = (char**)malloc(sizeof(char*) * (fs->nb - len));
	i = -1;
	len_cp = len;
	while (len < fs->nb)
		temp[++i] = fs->files[len++];
	strlst_del(&fs->files, len_cp);
	fs->files = temp;
	fs->nb -= len_cp;
}
