/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:59:40 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/24 17:58:35 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			check_opt(unsigned long *opt, char cand, char *av0)
{
	if (cand == 'R')
		*opt |= U_R;
	else if (cand == 'a')
		*opt |= L_A;
	else if (cand == 'l')
		*opt |= L_L;
	else if (cand == 'r')
		*opt |= L_R;
	else if (cand == 't')
		*opt |= L_T;
	else if (cand == 'u')
		*opt |= L_U;
	else
		usage_error(&cand, av0);
}

static int			get_opt(char **chnk, int len, unsigned long *opt
		, char *av0)
{
	int				i;
	unsigned int	j;

	i = -1;
	while (++i < len)
	{
		if (chnk[i][0] == '-' && chnk[i][1])
		{
			j = 0;
			while (++j < ft_strlen(chnk[i]))
				check_opt(opt, chnk[i][j], av0);
		}
		else
			break ;
	}
	return (i);
}

static int			check_path(char ***paths, int len)
{
	int				i;
	int				j;
	t_stat			sb;

	i = -1;
	while (++i < len)
	{
		if (lstat((*paths)[i], &sb))
		{
			usage_error((*paths)[i], NULL);
			j = i - 1;
			while (++j < len)
			{
				if (j + 1 == len)
					paths[0][j] = NULL;
				else
					paths[0][j] = paths[0][j + 1];
			}
			len--;
			i--;
			if (!len)
				exit(1);
		}
	}
	return (len);
}

int					validate(char **chnk, int len, unsigned long *opt,
		char ***paths)
{
	int				i;
	int				res;
	char			*av0;

	len--;
	av0 = chnk[0];
	chnk++;
	i = get_opt(chnk, len, opt, av0);
	res = len - i;
	if (res)
	{
		*paths = &chnk[i];
		*paths = lexi_sorting(*paths, res);
		res = check_path(paths, res);
	}
	return (res);
}
