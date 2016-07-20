/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:02:25 by telain            #+#    #+#             */
/*   Updated: 2016/07/20 16:12:37 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_type(t_data *d)
{
	if ((S_IFMT & d->s.st_mode) == S_IFSOCK)
		d->rights[0] = 's';
	else if ((S_IFMT & d->s.st_mode) == S_IFLNK)
		d->rights[0] = 'l';
	else if ((S_IFMT & d->s.st_mode) == S_IFBLK)
		d->rights[0] = 'b';
	else if ((S_IFMT & d->s.st_mode) == S_IFDIR)
		d->rights[0] = 'd';
	else if ((S_IFMT & d->s.st_mode) == S_IFCHR)
		d->rights[0] = 'c';
	else if ((S_IFMT & d->s.st_mode) == S_IFIFO)
		d->rights[0] = 'p';
}
