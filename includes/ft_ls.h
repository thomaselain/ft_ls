/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:24:35 by telain            #+#    #+#             */
/*   Updated: 2016/08/13 15:17:32 by telain           ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

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
	int				err_param;
	int				file_arg;
	int				displayed;
	t_file			**begin;
}					t_data;

/*
**	main.c
**	Apelle toutes les autres fonctions et initialise les variables
*/

int		read_file(t_data *d, char **av);
void	data_init(t_data *d);

/*
**	parse_arg.c
**	Gere les arguments et recupere les options utilisees
*/

int		parse_arg(int ac, char **av, t_data *d);
int		search_arg(char *av, t_data *d);
void	find_param(t_data *d, char **av);

/*
**	put_error.c
**	Affiche les cas d'erreur
*/

void	put_error(int err, char *file);

/*
**	get_rights.c
**	Recupere les droits d'un fichier et son type
*/

void	get_rights(t_file *f, struct stat *s);
void	get_urights(t_file *f, struct stat *s);
void	get_grights(t_file *f, struct stat *s);
void	get_orights(t_file *f, struct stat *s);
void	get_type(t_file *f, struct stat *s);

/*
**	list.c
**	Cree les nouveaux fichiers, les nouvelles listes
*/

void	new_list(t_data *d);
t_file	*new_file(t_file *previous, t_data *d, char *name);
void	sort_list(t_data *d, t_file *first, int i);
void	sort_list_time(t_data *d, t_file *first, int i);
void	swap_files(t_file *file);
int		date_cmp(char *date1, char *date2);
int		find_month(char *date);

/*
**	display_infos.c
**	Affiche les informations du fichier passe en parametre
*/

void	display_infos(t_file *f, t_data *d);
void	put_n_spaces(int n);
int		find_biggest_size(t_data *d);

/*
**	recursive.c
**	Pour l'option -R                     WORK IN PROGRESS
*/

int		recursive(t_data *d, t_file *folder);

/*
**	display_folder.c
**	Affiche les informations du dossier passe en parametre
*/

void	display_folder(t_data *d, t_file *file);

#endif
