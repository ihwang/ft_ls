/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:20:10 by tango             #+#    #+#             */
/*   Updated: 2020/01/19 16:21:19 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **chnk)
{
	char *opt;

	opt = NULL;
	if (ac != 1)
	{
		chnk++;
		chnk = validate(chnk, ac, &opt);
		//print_ls();
	}
	else
	{
		chnk = NULL;
	//	print_ls();
	}
	return (0);
}
