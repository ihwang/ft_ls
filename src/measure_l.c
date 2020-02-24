/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:31:52 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 16:12:17 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static unsigned long	get_len_sym(char *file, char *dir, t_stat sb,
									char **dot)
{
	char				buf[PATH_MAX];
	int					i;

	if ((sb.st_mode & S_IFLNK) != S_IFLNK)
		return (0);
	*dot = &(dir[ft_strlen(dir)]);
	dir = ft_strcat(dir, "/");
	dir = ft_strcat(dir, file);
	i = 0;
	if ((readlink(dir, buf, PATH_MAX)) > 0)
	{
		while (buf[i])
			i++;
		buf[i] = '\0';
	}
	**dot = '\0';
	return (i);
}

static void				measure_size_or_major(t_stat sb, t_len *len)
{
	unsigned long		nb;
	unsigned long		mi;
	unsigned long		mj;

	if (sb.st_rdev)
	{
		mi = ft_nbrlen(minor(sb.st_rdev)) <= 3 ?
			ft_nbrlen(minor(sb.st_rdev)) : 3;
		mj = ft_nbrlen(major(sb.st_rdev)) < 3 ?
			ft_nbrlen(major(sb.st_rdev)) : 3;
		nb = 1 + 1 + 1 + mi + mj;
		len->size = len->size > nb ? len->size : nb;
		len->minor = len->minor > mi ? len->minor : mi;
		len->major = len->major > mj ? len->major : mj;
	}
	else
	{
		len->size = len->size > ft_nbrlen(sb.st_size) ?
				len->size : ft_nbrlen(sb.st_size);
	}
}

static void				measure2(t_len *len, t_stat sb)
{
	unsigned long		temp;
	t_gp				*gp;

	if ((gp = getgrgid(sb.st_gid)))
		temp = ft_strlen(gp->gr_name);
	else
		temp = ft_nbrlen(sb.st_gid);
	len->gid = len->gid > temp ? len->gid : temp;
	measure_size_or_major(sb, len);
	len->sum = len->perm + len->link + len->uid + len->gid + len->size +
			len->date + len->fname + len->sym + LEN_EMPTY_L + 1;
}

int						measure_l(char *file, char *dir,
		unsigned long max, t_len *len)
{
	unsigned long		temp;
	char				*dot;
	t_stat				sb;
	t_pwd				*pwd;

	if (dir)
		len->is_d = get_sb(file, dir, &sb, &dot) ? NO_PERM : 0;
	else
		errno = lstat(file, &sb);
	if (len->is_d)
		return (max);
	len->link = len->link > ft_nbrlen(sb.st_nlink) ?
				len->link : ft_nbrlen(sb.st_nlink);
	if ((pwd = getpwuid(sb.st_uid)))
		temp = ft_strlen(pwd->pw_name);
	else
		temp = ft_nbrlen(sb.st_uid);
	len->uid = len->uid > temp ? len->uid : temp;
	len->fname = len->fname > ft_strlen(file) ? len->fname : ft_strlen(file);
	len->sym = len->sym > 4 + get_len_sym(file, dir, sb, &dot) ?
				len->sym : 4 + get_len_sym(file, dir, sb, &dot);
	measure2(len, sb);
	if (len->sum > max)
		return (len->sum);
	return (max);
}
