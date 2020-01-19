/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:02:53 by tango             #+#    #+#             */
/*   Updated: 2020/01/19 14:54:52 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage_error(char *error)
{
	if (!errno)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(*error);
		ft_putstr("\nusage: ./ft_ls [-Ralrt] [file ...]\n");
		exit(1);
	}
	else
	{
		ft_putstr("ft_ls: ");
		perror(error);
	}
}
