/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:30:55 by tango             #+#    #+#             */
/*   Updated: 2020/01/19 16:20:07 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_opt(char **chnk, int len, char **opt)
{
	char	*tmp;
	int		i;

	i = -1;
	*opt = ft_strnew(1);
	while (++i < len)
	{
		if (chnk[i][0] == '-' && chnk[i][1])
		{
			tmp = ft_strjoin(*opt, &chnk[i][1]);
			free(*opt);
			*opt = tmp;
		}
		else
			break ;
	}
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

char		**validate(char **chnk, int len, char **opt)
{
	int i;

	len--;
	i = get_opt(chnk, len, opt);
	check_opt(*opt);
	if (opt[0][0] == '\0')
		ft_strdel(opt);
	if (chnk[i] != NULL)
		return (&chnk[i]);
	else
		return (NULL);
}
