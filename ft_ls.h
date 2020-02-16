/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:24:10 by tango             #+#    #+#             */
/*   Updated: 2020/02/15 20:49:48 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LEN_EMPTY_L 9
# define LEN_PERM 11
# define LEN_DATE 12

# include <time.h>
# include <sys/stat.h>
# include <sys/syslimits.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct		s_len
{
	unsigned long	perm;
	unsigned long	link;
	unsigned long	uid;
	unsigned long	gid;
	unsigned long	size;
	unsigned long	date;
	unsigned long	fname;
	unsigned long	sym;
	unsigned long	sum;

	int				dir; // need to be checked
	int				l_nb; //need to be checked
}					t_len;

typedef struct		s_files
{
	char			**files;
	int				nb;
}					t_files;

typedef struct		s_dirs
{
	char			**dirs;
	int				nb;
	int				nb_cp;
	int				is_no; // need to be checked
	int				b;
	int				re;
	int				depth;
}					t_dirs;

typedef struct		s_l
{
	char			**app_l;
	int				nb;
	int				total;
//	char			type;
}					t_l;

void				usage_error(char *error);
int					validate(char **chnk, int len, char **opt, char ***files);
void				ft_ls(char **files, char *opt, int count);
void				extract_dirs(t_dirs *ds, char **paths, int nb);
void				extract_files(t_files *fs, char **paths, int nb);
void				a_del_invi(t_files *fs);
char				**lexi_sorting(char **files, int nb);
void				r_sorting(t_files *fs);
void				t_sorting(t_files *fs);
void				l_add_info(t_files *fs, t_l *l, char *dir);
void				strlst_del(char ***target, int nb);
void				no_dirs(t_dirs *ds);
void				print_dirs(char *opt, t_dirs *ds);
void				init_dirp(DIR **dirp);
#endif
