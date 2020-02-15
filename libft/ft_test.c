/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:03:24 by tango             #+#    #+#             */
/*   Updated: 2020/01/15 18:34:37 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include "./libft/libft.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_test(char *prev)
{
	DIR *pdir;
	struct dirent *dir;
	char *path;

	while ((pdir = opendir(prev)))
	{
		
		
		
int		main(void)
{
	ft_test("..");
	return (0);
}

int		main(int ac, char **av)
{
	DIR *pdir;
	struct dirent *dir;
	char *path;

	if (ac != 2)
		return (1);
	while ((pdir = opendir("..")))
	{
		
	
	while ((dir = readdir(pdir)))
	{
		
		if (dir->d_name[0] != '.')
		{
			ft_putstr(dir->d_name);
			write(1, "\n", 1);
		}
	}
	return (0);
}
