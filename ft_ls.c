/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:20:10 by tango             #+#    #+#             */
/*   Updated: 2020/01/19 18:05:43 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **chnk)
{
	char *opt;
	char **paths;
	int	nb;

	opt = NULL;
	paths = NULL;
	nb = 0;
	if (ac != 1)
	{
		chnk++;
		nb = validate(chnk, ac, &opt, &paths);
	}
//	print_ls(paths, opt, nb);
	return (0);
}
