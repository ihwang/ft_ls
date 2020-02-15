/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_a_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:24:59 by tango             #+#    #+#             */
/*   Updated: 2020/02/15 18:49:21 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned long			get_len_num(int num)
{
	int len;

	if (!num)
		return (1);
	len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void			get_sb(char *file, char *dir, struct stat *sb, char **dot)
{
	*dot = &(dir[ft_strlen(dir)]);
	dir = ft_strcat(dir, "/");
	dir = ft_strcat(dir, file);
	if (lstat(dir, sb))
		exit(1);//should be fixed
	**dot = '\0';
}

unsigned long			get_len_sym(char *file, char *dir, struct stat sb,
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
	
int					measure_l(char *file, char *dir, unsigned long  max,
		t_len *len)
{
	unsigned long	temp;
	char			*dot;
	struct			stat sb;

	if (dir)
		get_sb(file, dir, &sb, &dot);
	else
		stat(file, &sb) ? exit(1) : 0;
	len->link = len->link > get_len_num(sb.st_nlink) ?
				len->link : get_len_num(sb.st_nlink);
	temp = ft_strlen(getpwuid(sb.st_uid)->pw_name);
	len->uid = len->uid > temp ? len->uid : temp;
	temp = ft_strlen(getgrgid(sb.st_gid)->gr_name);
	len->gid = len->gid > temp ? len->gid : temp;
	len->size = len->size > get_len_num(sb.st_size) ?
				len->size : get_len_num(sb.st_size);
	len->fname = len->fname > ft_strlen(file) ? len->fname : ft_strlen(file);
	len->sym = len->sym > 4 + get_len_sym(file, dir, sb, &dot) ?
				len->sym : 4 + get_len_sym(file, dir, sb, &dot);
	len->sum = len->perm + len->link + len->uid + len->gid + len->size +
				len->date + len->fname + len->sym + LEN_EMPTY_L + 1;
	if (len->sum > max)
		return (len->sum);
	return (max);
}

char		*make_w(unsigned long big, unsigned long small)
{
	unsigned long i;
	char *white;

	white = (char*)malloc(big - small + 1);
	i = 0;
	while (i < big - small)
		white[i++] = ' ';
	white[i] = '\0';
	free(white);
	return (white);
}

char		*get_formatted_date1(char *date)
{
	char *temp;

	temp = date;
	date += 4;
	temp[16] = '\0';
	return (date);
}


char		get_mode(struct stat sb)
{
	if (sb.st_mode & S_IFREG)
	{
		if ((sb.st_mode & S_IFLNK) == S_IFLNK)
			return ('l');
		else if ((sb.st_mode & S_IFSOCK) == S_IFSOCK)
			return ('s');
		else
			return ('-');
	}
	else if (sb.st_mode & S_IFIFO)
		return ('p');
	else if (sb.st_mode & S_IFCHR)
		return ('c');
	else if (sb.st_mode & S_IFDIR)
		return ('d');
	else
		return ('b');
}

void		permission(char **perm_board, struct stat sb)
{
	unsigned short flag;
	int i;

	*perm_board = (char*)malloc(sizeof(char) * 12);
	perm_board[0][0] = get_mode(sb);
	i = 0;
	flag = 0400;
	while (++i < 10)
	{
		if ((sb.st_mode & 0777) & flag)
		{
			if (i % 3 == 1)
				perm_board[0][i] = 'r';
			else if (i % 3 == 2)
				perm_board[0][i] = 'w';
			else
				perm_board[0][i] = 'x';
		}
		else
			perm_board[0][i] = '-';
		flag >>= 1;
	}
	perm_board[0][i] = ' ';
	perm_board[0][++i] = '\0';
}

int			cal_total(struct stat sb)
{
	int		size;

	if (sb.st_mode & S_IFDIR)
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

int			make_line2(struct stat sb, char *app_l, t_len lens, int total)
{
	char *itoa;

	itoa = ft_itoa(sb.st_nlink);
	app_l = ft_strcat(app_l, itoa);
	ft_strdel(&itoa);
	app_l = ft_strcat(app_l, " ");
	app_l = ft_strcat(app_l, getpwuid(sb.st_uid)->pw_name);	
	app_l = ft_strcat(app_l,
		make_w(lens.uid, ft_strlen(getpwuid(sb.st_uid)->pw_name)));
	app_l = ft_strcat(app_l, "  ");
	app_l = ft_strcat(app_l, getgrgid(sb.st_gid)->gr_name);
	app_l = ft_strcat(app_l,
		make_w(lens.gid, ft_strlen(getgrgid(sb.st_gid)->gr_name)));
	app_l = ft_strcat(app_l, "  ");
	app_l = ft_strcat(app_l,
		make_w(lens.size, get_len_num(sb.st_size)));
	itoa = ft_itoa(sb.st_size);
	app_l = ft_strcat(app_l, itoa);
	ft_strdel(&itoa);
	app_l = ft_strcat(app_l, " ");
	app_l = ft_strcat(app_l, get_formatted_date1(ctime(&sb.st_mtime)));
	app_l = ft_strcat(app_l, " ");
	total += cal_total(sb);
	return (total);
}

char		*get_link(char *file, char *dir, char **dot, char **link_board)
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
		exit(1);//needs to be checked
	i = 0;
	while (link_board[0][i])
		i++;
	link_board[0][i] = '\0';
	**dot = '\0';
	return (*link_board);
}	

int			make_lines1(char *file, char *dir, char *app_l, t_len lens)
{
	struct stat sb;
	//char	*perm_board;
	char	*reuse_board;
	//char	*link_board;
	char	*dot;
	int	total;

	total = 0;
	dir ? get_sb(file, dir, &sb, &dot) : lstat(file, &sb);
	permission(&reuse_board, sb);
	app_l = ft_strcat(app_l, reuse_board);
	ft_strdel(&reuse_board);
	app_l = ft_strcat(app_l, " ");
	app_l = ft_strcat(app_l, make_w(lens.link, get_len_num(sb.st_nlink)));
	total += make_line2(sb, app_l, lens, total);
	app_l = ft_strcat(app_l, file);
	if ((sb.st_mode & S_IFLNK) == S_IFLNK)
	{
		app_l = ft_strcat(app_l, " -> ");
		app_l = ft_strcat(app_l, get_link(file, dir, &dot, &reuse_board));
		ft_strdel(&reuse_board);
	}
	app_l = ft_strcat(app_l, "\0");	
	return (total);
}

void		clean_lens(t_len *lens)
{
	lens->perm = LEN_PERM;
	lens->link = 0;
	lens->uid = 0;
	lens->gid = 0;
	lens->size = 0;
	lens->date = LEN_DATE;
	lens->fname = 0;
	lens->sym = 0;
	lens->sum = 0;
	lens->dir = 0;
	lens->l_nb = 0;
}

void				add_total(t_l *l, t_len len)
{
	unsigned long	i;
	char			*total;

	i = -1;
	
	while (++i < len.sum)
		l->app_l[0][i] = '\0';
	if (l->nb)
	{
		total = ft_itoa(l->total);
		l->app_l[0] = ft_strcat(l->app_l[0], "total ");
		l->app_l[0] = ft_strcat(l->app_l[0], total);
		ft_strdel(&total);
	}
}

void		dir_mm(t_files *fs, t_len *lens, t_l *l, char *dir)
{
	int		max;
	int		i;

//	l->type = 'd';
	i = -1;
	max = 0;
	l->app_l = (char**)malloc(sizeof(char*) * (l->nb + 1));
	while (++i < l->nb)
		max = measure_l(fs->files[i], dir, max, lens);
	i = -1;
	max += 1;
	l->nb = l->nb ? l->nb + 1 : 0;
	while (++i < l->nb)
		l->app_l[i] = (char*)malloc(sizeof(char) * max);
	l->nb = l->nb ? l->nb - 1 : 0;
}

void		file_mm(t_files *fs, t_len *lens, t_l *l)
{
	int		max;
	int		i;

	i = -1;
	max = 0;
	l->app_l = (char**)malloc(sizeof(char*) * (l->nb));
	while (++i < l->nb)
		max = measure_l(fs->files[i], NULL, max, lens);
	max += 1;
	i = -1;
	while (++i < l->nb)
		l->app_l[i] = (char*)malloc(sizeof(char) * max);
}

void		l_add_info(t_files *fs, t_l *l, char *dir)
{
	int		i;
	t_len	lens;

	clean_lens(&lens);
	l->nb = fs->nb;
	if (dir)
	{
		if (!l->nb)
			return ;
		dir_mm(fs, &lens, l, dir);
	}
	else
		file_mm(fs, &lens, l);
	i = -1;
	while (++i < l->nb)
		l->total += dir ? make_lines1(fs->files[i], dir, l->app_l[i + 1], lens)
			: make_lines1(fs->files[i], dir, l->app_l[i], lens);
	dir ? add_total(l, lens) : 0;
	strlst_del(&fs->files, fs->nb);
	l->nb = dir ? l->nb + 1 : l->nb;
}
/*
void		a_del_invi(t_files *fs)
{
	int nb_cp;
	char **temp;

	nb_cp = fs->nb;
	while (nb_cp--)
	{
		if (fs->files[0][0] == '.')
		{
			temp = &(fs->files[1]);
			ft_strdel(&fs->files[0]);
			fs->files = temp;
			fs->nb--;
		}
	}
}*/

void		a_del_invi(t_files *fs)
{
	int		len;
	int		len_cp;
	int		i;
	char	**temp;

	len = 0;
	i = -1;
	while (++i < fs->nb)
	{
		if (fs->files[i][0] == '.')
			len++;
		else
			break ;
	}
	len_cp = len;
	temp = (char**)malloc(sizeof(char*) * (fs->nb - len));
	i = -1;
	while (len < fs->nb)
	{
		temp[++i] = (char*)malloc(NAME_MAX);
		temp[i] = ft_strcat(temp[i], fs->files[len++]);
	}
	strlst_del(&fs->files, fs->nb);
	fs->files = temp;
	fs->nb -= len_cp;
}
