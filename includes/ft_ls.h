/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:35 by telain            #+#    #+#             */
/*   Updated: 2016/07/20 17:41:32 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <pwd.h>
# define ERR_NOFILE -1
# define ERR_USAGE 1
# define ERR_NORIGHT 2

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
	struct group	*grp;;
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

#endif
