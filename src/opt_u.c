/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:25:10 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/24 17:28:32 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char		*get_date(char *date, long tspec)
{
	char		*last;
	char		*year;

	date += 4;
	if (ft_strcmp(&date[16], "2020\n"))
	{
		if (time(NULL) - tspec > TIME_GAP || time(NULL) < tspec)
		{
			last = (char*)malloc(13);
			year = (char*)malloc(5);
			last[0] = '\0';
			year[0] = '\0';
			ft_strncpy(last, date, 6);
			last[6] = '\0';
			ft_strcat(last, "  ");
			ft_strncpy(year, &date[ft_strlen(date) - 5], 4);
			ft_strcat(last, year);
			free(year);
			free(last);
			return (last);
		}
	}
	date[12] = '\0';
	return (date);
}

void			make_date(t_stat sb, char *board, t_len lens)
{
	if (lens.opt & L_U)
		ft_strcat(board, get_date(ctime(&sb.st_atime), sb.st_atime));
	else
		ft_strcat(board, get_date(ctime(&sb.st_mtime), sb.st_mtime));
}

long			get_time(char *file, char *dir, unsigned long opt)
{
	t_stat		sb;
	char		*dot;

	if (dir)
	{
		if (!get_sb(file, dir, &sb, &dot))
		{
			if (opt & L_U)
				return (sb.st_atimespec.tv_sec);
			else
				return (sb.st_mtimespec.tv_sec);
		}
		exit(1);
	}
	else
	{
		if (!(lstat(file, &sb)))
		{
			if (opt & L_U)
				return (sb.st_atimespec.tv_sec);
			else
				return (sb.st_mtimespec.tv_sec);
		}
		exit(1);
	}
}
