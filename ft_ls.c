/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:20:10 by tango             #+#    #+#             */
/*   Updated: 2020/02/14 11:46:39 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	char	*opt;
	char	**paths;
	int		nb;

	opt = NULL;
	paths = NULL;
	nb = 0;
	av++;
	if (ac != 1)
		nb = validate(av, ac, &opt, &paths);
	if (ac != 1 && opt == NULL)
	   	if (paths[0] == NULL)
			exit(1);//should be fixed
	ft_ls(paths, opt, nb);
	return (0);
}
