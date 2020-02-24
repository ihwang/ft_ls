/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:47:32 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 16:05:15 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char			get_mode(t_stat sb)
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

static void			permission(char **perm_board, t_stat sb)
{
	unsigned short	flag;
	int				i;

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

void				perm_clean(t_stat sb, char *line)
{
	char			*perm_board;

	permission(&perm_board, sb);
	ft_strcat(line, perm_board);
	ft_strdel(&perm_board);
}
