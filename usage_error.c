/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 23:02:53 by tango             #+#    #+#             */
/*   Updated: 2020/02/14 20:00:25 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage_error(char *error)
{
	if (ft_strlen(error) > NAME_MAX)
	{
		errno = ENAMETOOLONG;
		ft_putstr("ft_ls: ");
		perror(error);
		exit(1);
	}
	else if (!errno)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(*error);
		ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
		//ft_putstr("\nusage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
		exit(1);
	}
	else
	{
		ft_putstr("ft_ls: ");
		perror(error);
		errno = 0;
	}
}
