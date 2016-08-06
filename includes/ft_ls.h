/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:35 by telain            #+#    #+#             */
/*   Updated: 2016/08/06 17:00:59 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
# include <time.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# define ERR_NOFILE -1
# define ERR_USAGE 1
# define ERR_NORIGHT 2

typedef struct		s_file
{
	char			*file_name;
	char			*date;
	char			*rights;
	char			*grp_name;
	char			*usr_name;
	char			*path;
	int				links;
	int				size;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef struct		s_data
{
	char			*name;
	char			*param;
	char			*rights;
	int				size;
	int				cur_arg;
	DIR				*dir;
	struct dirent	*ent;
	int				biggest;
	t_file			**begin;
}					t_data;

/*
**	main.c
*/

void	read_file(t_data *d);
void	data_init(t_data *d);

/*
**	parse_arg.c
*/

int		parse_arg(int ac, char **av, t_data *d);
int		search_arg(char *av);
void	find_param(t_data *d, char **av);

/*
**	put_error.c
*/

void	put_error(int err, char *file);

/*
**	get_rights.c
*/

void	get_rights(t_file *f, struct stat *s);
void	get_urights(t_file *f, struct stat *s);
void	get_grights(t_file *f, struct stat *s);
void	get_orights(t_file *f, struct stat *s);
void	get_type(t_file *f, struct stat *s);

/*
**	list.c
*/

void	new_list(t_data *d);
t_file	*new_file(t_file *previous, t_data *d, char *name);
void	sort_list(t_data *d, t_file *first, int i);
void	swap_files(t_file *file1, t_file *file2);

/*
**	display_infos.c
*/

void	display_infos(t_file *f, t_data *d);
void	put_n_spaces(int n);
int		find_biggest_size(t_data *d);

#endif
