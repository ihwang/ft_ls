/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:02:53 by tango             #+#    #+#             */
/*   Updated: 2020/02/24 18:15:11 by ihwang           ###   ########.fr       */
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

static void	p_file_name(char *av0)
{
	char	*dot;

	if (av0[0] == '/')
		ft_putstr(av0);
	else
	{
		dot = ft_strchr(av0, '/') + 1;
		ft_putstr(dot);
	}
}

void		usage_error(char *error, char *av0)
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
		p_file_name(av0);
		ft_putstr(": illegal option -- ");
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
