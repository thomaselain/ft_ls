/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:35 by telain            #+#    #+#             */
/*   Updated: 2016/07/18 20:26:14 by telain           ###   ########.fr       */
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

typedef struct		s_data
{
	char			*name;
	char			*param;
	int				cur_arg;
	DIR				*dir;
	struct dirent	*ent;
	struct stat		s;
	struct passwd	pswd;
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

/*
**	put_error.c
*/

void	put_error(int err);

#endif
