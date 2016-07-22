/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:35 by telain            #+#    #+#             */
/*   Updated: 2016/07/22 15:41:49 by telain           ###   ########.fr       */
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
	char			*name;
	char			*date;
	int				right;
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
	struct stat		s;
	struct passwd	*pswd;
	struct group	*grp;
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
int		search_arg(char *av, t_data *d);

/*
**	put_error.c
*/

void	put_error(int err, t_data *d);

/*
**	get_rights.c
*/

void	get_rights(t_data *d, struct stat *s);
void	get_urights(t_data *d, struct stat *s);
void	get_grights(t_data *d, struct stat *s);
void	get_orights(t_data *d, struct stat *s);

/*
**	get_type.c
*/

void	get_type(t_data *d);

/*
**	list.c
*/

void	new_list(t_data *d);
t_file	*new_file(t_file *previous, char *name, char *date);

#endif
