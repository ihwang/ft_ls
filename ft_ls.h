/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:24:10 by tango             #+#    #+#             */
/*   Updated: 2020/01/19 15:33:07 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/libft.h"

void	usage_error(char *error);
char	**validate(char **chnk, int len, char **opt);

#endif
