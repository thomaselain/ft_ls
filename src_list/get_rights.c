/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:32:09 by telain            #+#    #+#             */
/*   Updated: 2016/07/21 17:14:02 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_rights(t_data *d, struct stat *s)
{
	get_urights(d, s);
	get_grights(d, s);
	get_orights(d, s);
	get_type(d);
}

void	get_urights(t_data *d, struct stat *s)
{
	if ((s->st_mode & S_IRUSR) == S_IRUSR)
		d->rights[1] = 'r';
	if ((s->st_mode & S_IWUSR) == S_IWUSR)
		d->rights[2] = 'w';
	if ((s->st_mode & S_IXUSR) == S_IXUSR)
		d->rights[3] = 'x';
}

void	get_grights(t_data *d, struct stat *s)
{
	if ((s->st_mode & S_IRGRP) == S_IRGRP)
		d->rights[4] = 'r';
	if ((s->st_mode & S_IWGRP) == S_IWGRP)
		d->rights[5] = 'w';
	if ((s->st_mode & S_IXGRP) == S_IXGRP)
		d->rights[6] = 'x';
}

void	get_orights(t_data *d, struct stat *s)
{
	if ((s->st_mode & S_IROTH) == S_IROTH)
		d->rights[7] = 'r';
	if ((s->st_mode & S_IWOTH) == S_IWOTH)
		d->rights[8] = 'w';
	if ((s->st_mode & S_IXOTH) == S_IXOTH)
		d->rights[9] = 'x';
}
