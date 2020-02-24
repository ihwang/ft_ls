/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_etc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:35:24 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/23 16:10:41 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		make_uid(t_stat sb, char *ap, t_len lens)
{
	t_pwd	*pwd;

	if ((pwd = getpwuid(sb.st_uid)))
	{
		ft_strcat(ap, pwd->pw_name);
		ft_strcat(ap, mk_w(lens.uid, ft_strlen(pwd->pw_name)));
	}
	else
	{
		itox_clean(ap, sb.st_uid, ft_itoa);
		ft_strcat(ap, mk_w(lens.uid, ft_nbrlen(sb.st_uid)));
	}
}

void		make_gid(t_stat sb, char *ap, t_len lens)
{
	t_gp	*gp;

	if ((gp = getgrgid(sb.st_gid)))
	{
		ft_strcat(ap, gp->gr_name);
		ft_strcat(ap, mk_w(lens.gid, ft_strlen(gp->gr_name)));
	}
	else
	{
		itox_clean(ap, sb.st_gid, ft_itoa);
		ft_strcat(ap, mk_w(lens.gid, ft_nbrlen(sb.st_gid)));
	}
}
