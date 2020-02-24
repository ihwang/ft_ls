/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:02:53 by tango             #+#    #+#             */
/*   Updated: 2020/02/23 16:07:59 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		perror_print(char *dir)
{
	ft_putstr("ft_ls: ");
	perror(dir);
	errno = 0;
}

void		perm_check(char *dir, t_dirs *ds)
{
	DIR		*dirp;
	char	*pt;

	if ((dirp = opendir(dir)))
		closedir(dirp);
	if (errno == 13)
	{
		if (ds->re == 0)
		{
			ft_putstr("ft_ls: : ");
			perror("");
			errno = 0;
		}
		else
		{
			if (!ft_strrchr(dir, '/'))
				perror_print(dir);
			else
			{
				pt = ft_strrchr(dir, '/') + 1;
				perror_print(pt);
			}
		}
	}
}

void		usage_error(char *error)
{
	if (ft_strlen(error) > NAME_MAX)
	{
		errno = ENAMETOOLONG;
		ft_putstr("ft_ls: ");
		perror(error);
		exit(1);
	}
	else if (!errno)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(*error);
		ft_putstr("\nusage: ft_ls [-Ralrtu] [file ...]\n");
		exit(1);
	}
	else
	{
		ft_putstr("ft_ls: ");
		perror(error);
		errno = 0;
	}
}
