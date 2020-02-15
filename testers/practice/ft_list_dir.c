/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:03:24 by tango             #+#    #+#             */
/*   Updated: 2020/01/21 17:56:35 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "libft/libft.h"

int		main(int ac, char **av)
{
	DIR *dirp;
	struct dirent *dir;

	if (ac != 2)
		return (1);
	dirp = opendir(av[1]);
	while ((dir = readdir(dirp)))
	{
		if (dir->d_name[0] != '.')
		{
			ft_putstr(dir->d_name);
			write(1, "\n", 1);
		}
	}
	return (0);
}
