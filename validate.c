/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:30:55 by tango             #+#    #+#             */
/*   Updated: 2020/02/14 11:42:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		thinout_opt(char **opt)
{
	char *p_opt;
	char *target;
	
	p_opt = *opt;
	while (*p_opt)
	{
		target = p_opt + 1;
		while (*target)
		{
			if (*p_opt == *target)
				*target = *(target + 1);
			target++;
		}
		p_opt++;
	}			
}

int			get_opt(char **chnk, int len, char **opt)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < len)
	{
		if (chnk[i][0] == '-' && chnk[i][1])
		{
			if (*opt == NULL)
				*opt = ft_strnew(1);
			tmp = ft_strjoin(*opt, &chnk[i][1]);
			ft_strdel(opt);
			*opt = tmp;
		}
		else
		{
			break ;
		}
	}
	if (*opt)
		thinout_opt(opt);
	return (i);
}

int			check_opt(char *opt)
{
	int i;

	i = -1;
	while (opt[++i])
		if (!(opt[i] == 'R' || opt[i] == 'a' || opt[i] == 'l' ||
			opt[i] == 'r' || opt[i] == 't'))
			usage_error(&opt[i]);
	return (0);
}	

int			check_path(char ***paths, int len)
{
	int i;
	int j;
	struct stat sb;

	i = -1;
	while (++i < len)
	{
		if (stat((*paths)[i], &sb))
		{
			usage_error((*paths)[i]);
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
		}
	}
	return (len);
}

int			validate(char **chnk, int len, char **opt, char ***paths)
{
	int i;
	int res;

	len--;
	i = get_opt(chnk, len, opt);
	if (i)
		check_opt(*opt);
	res = len - i;
	if (res)
	{
		*paths = &chnk[i];
		*paths = lexi_sorting(*paths, res);
		res = check_path(paths, res);
	}
	return (res);
}
