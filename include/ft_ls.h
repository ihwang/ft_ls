/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tango <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:24:10 by tango             #+#    #+#             */
/*   Updated: 2020/02/23 21:12:44 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LEN_EMPTY_L 9
# define LEN_PERM 11
# define LEN_DATE 12
# define PATH_MAX 512
# define NAME_MAX 255
# define NO_PERM 1
# define TIME_GAP 15724800
# define U_R 01
# define L_A 02
# define L_L 04
# define L_R 010
# define L_T 020
# define L_U 040

# include <time.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/xattr.h>
# include "../libft/libft.h"

char					*g_sorted;

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct passwd	t_pwd;
typedef struct group	t_gp;

typedef struct			s_len
{
	unsigned long		perm;
	unsigned long		link;
	unsigned long		uid;
	unsigned long		gid;
	unsigned long		size;
	unsigned long		date;
	unsigned long		fname;
	unsigned long		sym;
	unsigned long		minor;
	unsigned long		major;
	unsigned long		is_d;
	unsigned long		sum;
	unsigned long		opt;
}						t_len;

typedef struct			s_files
{
	char				**files;
	int					nb;
	unsigned long		opt;
}						t_files;

typedef struct			s_dirs
{
	char				**dirs;
	int					nb;
	int					nb_cp;
	int					b;
	int					re;
	int					depth;
	unsigned long		opt;
}						t_dirs;

typedef struct			s_l
{
	char				**app_l;
	int					nb;
	int					total;
	unsigned long		opt;
}						t_l;

long					get_time(char*file, char *dir, unsigned long opt);
void					make_date(t_stat sb, char *board, t_len lens);
void					make_uid(t_stat sb, char *ap, t_len lens);
void					make_gid(t_stat sb, char *ap, t_len lens);
void					itox_clean(char *line, int nb, char *(itox)(int));
void					usage_error(char *error);
void					perm_check(char *dir, t_dirs *ds);
int						check_dir(char *path);
void					ft_ls(char **files, unsigned long opt, int count);
void					extract_dirs(t_dirs *ds, char **paths, int nb);
void					extract_files(t_files *fs, char **paths, int nb);
int						make_lines1(char *file, char *dir, char *app_l,
		t_len lens);
int						measure_l(char *file, char *dir,
		unsigned long max, t_len *len);
void					l_add_info(t_files *fs, t_l *l, char *dir);
void					t_sorting(t_files *fs, char *dir);
char					**lexi_sorting(char **files, int nb);
void					r_sorting(t_files *fs);
void					a_del_invi(t_files *fs);
void					perm_clean(t_stat sb, char *line);
void					print_dirs(unsigned long opt, t_dirs *ds);
void					cut_file(t_files *d);
void					dec_depth(char *dir, t_dirs *ds, unsigned long opt);
int						shaping_dirs(char *dir, char *d, unsigned long opt,
		t_dirs *ds);
void					clean_lens(t_len *lens, t_files *fs);
void					clean_l(t_l *l, unsigned long opt);
void					clean_ds_fs(t_dirs *ds, t_files *fs,
		unsigned long opt);
int						get_sb(char *file, char *dir, t_stat *sb, char **dot);
char					*get_formatted_date1(char *date, t_stat sb);
unsigned long			get_len_num(int num);
void					no_dirs(t_dirs *ds);
char					*mk_w(unsigned long big, unsigned long small);
void					p_d_n(char *dir, t_dirs *ds);
void					print(char **target, int nb);
void					init_dirp(DIR **dirp);
void					ds_del(char **dir, int nb);
void					strlst_del(char ***target, int nb);
int						validate(char **chnk, int len, unsigned long *opt,
		char ***files);

#endif
