/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:30:49 by tango             #+#    #+#             */
/*   Updated: 2020/01/25 18:36:32 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "./libft/libft.h"

#include <stdio.h>

void	p_ftype(struct stat sb)
{
	if (sb.st_mode & S_IFIFO)
		ft_putstr("fifo");
	else if (sb.st_mode & S_IFCHR)
		ft_putstr("character device");
	else if(sb.st_mode & S_IFDIR)
		ft_putstr("Directory");
	else if (sb.st_mode & S_IFREG)
		ft_putstr("regular");
	else if (sb.st_mode & S_IFBLK)
		ft_putstr("block device");
	else if (sb.st_mode & S_IFLNK)
		ft_putstr("symbolic link");
	else if (sb.st_mode & S_IFSOCK)
		ft_putstr("socket");
	else if (sb.st_mode & S_IFWHT)
		ft_putstr("whiteour");
}	

void	p_perm(struct stat sb)
{
	unsigned short flag;
	char buf[10];
	int i;

	i = -1;
	flag = 0400;
	while (++i < 9)
	{
		if ((sb.st_mode & 0777) & flag)
		{
			if (i % 3 == 0)
				buf[i] = 'r';
			else if (i % 2 == 1)
				buf[i] = 'w';
			else
				buf[i] = 'x';
		}
		else
			buf[i] = '-';
		flag >>= 1;
	}
	buf[i] = '\0';
	ft_putstr(buf);
}
	
void	get_formatted_date(char *date)
{
	date += 4;
	date[12] = '\0';
	ft_putstr(date);
}

int		get_file_info(char *fname)
{
	struct stat sb;

	if (stat(fname, &sb))
		return (-1);
	ft_putstr("Name: ");
	ft_putstr(fname);
	ft_putstr("\nType: ");
	p_ftype(sb);
	ft_putstr("\nModes: ");
	p_perm(sb);
	ft_putstr("\nNumber of links: ");
	ft_putnbr(sb.st_nlink);
	ft_putstr("\nOwner: ");
	ft_putstr(getpwuid(sb.st_uid)->pw_name);
	ft_putstr("\nStaff: ");
	ft_putstr(getgrgid(sb.st_gid)->gr_name);
	ft_putstr("\nSize: ");
	ft_putnbr(sb.st_size);
	ft_putstr("\nLast modification date: ");
	get_formatted_date(ctime(&sb.st_mtime));
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char **av)
{
	struct stat sb;

	if (ac != 2)
		return (1);
	if (!stat(av[1], &sb))
	{
		get_file_info(av[1]);
	}
	return (0);
}
