/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:19:58 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 17:01:36 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int	cal_total(t_stat sb)
{
	int		size;

	if ((sb.st_mode & S_IFDIR) == S_IFDIR)
		return (0);
	size = sb.st_size;
	if (size % sb.st_blksize)
	{
		size /= sb.st_blksize;
		size++;
		size *= 8;
	}
	else
	{
		size /= sb.st_blksize;
		size *= 8;
	}
	return (size);
}

static char	*get_link(char *file, char *dir, char **dot, char **link_board)
{
	int		i;

	*link_board = (char*)malloc(sizeof(char) * PATH_MAX);
	*dot = &(dir[ft_strlen(dir)]);
	dir = ft_strcat(dir, "/");
	dir = ft_strcat(dir, file);
	i = -1;
	while (++i < PATH_MAX)
		link_board[0][i] = '\0';
	if (readlink(dir, *link_board, PATH_MAX) < 0)
		exit(1);
	i = 0;
	while (link_board[0][i])
		i++;
	link_board[0][i] = '\0';
	**dot = '\0';
	return (*link_board);
}

static void	make_size_or_major(t_stat sb, char *ap, t_len lens)
{
	if (sb.st_rdev || ap[0] == 'c' || ap[0] == 'b')
	{
		ft_strcat(ap, mk_w(lens.major + 1, ft_nbrlen(major(sb.st_rdev))));
		if (major(sb.st_rdev))
			itox_clean(ap, major(sb.st_rdev), ft_itoa);
		else
			ft_strcat(ap, "0");
		ft_strcat(ap, ", ");
		if (ft_nbrlen(minor(sb.st_rdev)) < 4)
		{
			ft_strcat(ap, mk_w(lens.minor, ft_nbrlen(minor(sb.st_rdev))));
			itox_clean(ap, minor(sb.st_rdev), ft_itoa);
		}
		else
			itox_clean(ap, minor(sb.st_rdev), ft_itoh);
	}
	else
	{
		ft_strcat(ap, mk_w(lens.size, ft_nbrlen(sb.st_size)));
		itox_clean(ap, sb.st_size, ft_itoa);
	}
}

static int	make_line2(t_stat sb, char *ap, t_len l, int total)
{
	char	*temp;

	temp = (char*)malloc(sizeof(char) * (l.sum - 12));
	temp[0] = '\0';
	ft_strcat(ap, mk_w(l.link, ft_nbrlen(sb.st_nlink)));
	itox_clean(ap, sb.st_nlink, ft_itoa);
	ft_strcat(ap, " ");
	make_uid(sb, ap, l);
	ft_strcat(ap, "  ");
	make_gid(sb, ap, l);
	ft_strcat(ap, "  ");
	make_size_or_major(sb, ap, l);
	ft_strcat(ap, " ");
	make_date(sb, temp, l);
	ft_strcat(temp, " ");
	ft_strcat(ap, temp);
	ft_strdel(&temp);
	total += cal_total(sb);
	return (total);
}

int			make_lines1(char *file, char *dir, char *ap, t_len lens)
{
	t_stat	sb;
	char	*reuse_board;
	char	*dot;
	int		total;

	total = 0;
	if (dir)
		if (get_sb(file, dir, &sb, &dot))
			return (0);
	if (!dir)
		lstat(file, &sb);
	perm_clean(sb, ap);
	ft_strcat(ap, " ");
	total += make_line2(sb, ap, lens, total);
	ft_strcat(ap, file);
	if ((sb.st_mode & S_IFLNK) == S_IFLNK)
	{
		ft_strcat(ap, " -> ");
		ft_strcat(ap, get_link(file, dir, &dot, &reuse_board));
		ft_strdel(&reuse_board);
	}
	ft_strcat(ap, "\0");
	return (total);
}
