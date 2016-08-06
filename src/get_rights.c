/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:32:09 by telain            #+#    #+#             */
/*   Updated: 2016/08/06 16:21:48 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_rights(t_file *f, struct stat *s)
{
	f->rights = ft_strdup("----------");
	get_urights(f, s);
	get_grights(f, s);
	get_orights(f, s);
	get_type(f, s);
}

void	get_urights(t_file *f, struct stat *s)
{
	if ((s->st_mode & S_IRUSR) == S_IRUSR)
		f->rights[1] = 'r';
	if ((s->st_mode & S_IWUSR) == S_IWUSR)
		f->rights[2] = 'w';
	if ((s->st_mode & S_IXUSR) == S_IXUSR)
		f->rights[3] = 'x';
}

void	get_grights(t_file *f, struct stat *s)
{
	if ((s->st_mode & S_IRGRP) == S_IRGRP)
		f->rights[4] = 'r';
	if ((s->st_mode & S_IWGRP) == S_IWGRP)
		f->rights[5] = 'w';
	if ((s->st_mode & S_IXGRP) == S_IXGRP)
		f->rights[6] = 'x';
}

void	get_orights(t_file *f, struct stat *s)
{
	if ((s->st_mode & S_IROTH) == S_IROTH)
		f->rights[7] = 'r';
	if ((s->st_mode & S_IWOTH) == S_IWOTH)
		f->rights[8] = 'w';
	if ((s->st_mode & S_IXOTH) == S_IXOTH)
		f->rights[9] = 'x';
}

void	get_type(t_file *f, struct stat *s)
{
	if ((S_IFMT & s->st_mode) == S_IFSOCK)
		f->rights[0] = 's';
	else if ((S_IFMT & s->st_mode) == S_IFLNK)
		f->rights[0] = 'l';
	else if ((S_IFMT & s->st_mode) == S_IFBLK)
		f->rights[0] = 'b';
	else if ((S_IFMT & s->st_mode) == S_IFDIR)
		f->rights[0] = 'd';
	else if ((S_IFMT & s->st_mode) == S_IFCHR)
		f->rights[0] = 'c';
	else if ((S_IFMT & s->st_mode) == S_IFIFO)
		f->rights[0] = 'p';
}
