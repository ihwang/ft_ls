/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:20:10 by tango             #+#    #+#             */
/*   Updated: 2020/02/23 19:24:43 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int					main(int ac, char **av)
{
	unsigned long	opt;
	char			**paths;
	int				nb;

	opt = 0;
	paths = NULL;
	nb = 0;
	av++;
	if (ac != 1)
		nb = validate(av, ac, &opt, &paths);
	if (ac != 1 && opt == 0)
		if (paths[0] == NULL)
			exit(1);
	ft_ls(paths, opt, nb);
	while (1);
	return (0);
}
