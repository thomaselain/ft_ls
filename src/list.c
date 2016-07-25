/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:41:00 by telain            #+#    #+#             */
/*   Updated: 2016/07/25 19:27:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	new_list(t_data *d)
{
	d->begin = ft_memalloc(sizeof(struct s_list**));
}

t_file	*new_file(t_file *previous, t_data *d, char *str)
{
	t_file			*new;
	struct stat		s;
	struct passwd	*pswd;
	struct group	*grp;

	new = ft_memalloc(sizeof(struct s_file*) * 10);
	new->file_name = ft_strjoin(d->name, new->file_name);
	if (ft_strcmp(new->file_name, str))
		new->file_name = ft_strjoin(d->name, str);
	if (stat(new->file_name, &s) != 0)
		put_error(ERR_NOFILE, new->file_name);
	pswd = getpwuid(s.st_uid);
	grp = getgrgid(s.st_gid);
	new->date =	ft_strdup(ft_strsub(ctime(&s.st_mtimespec.tv_sec), 4, 12));
	get_rights(new, &s);
	new->links = s.st_nlink;
	new->size = s.st_size;
	new->grp_name = grp->gr_name;
	new->usr_name = pswd->pw_name;
	new->next = NULL;
	if (previous)
		previous->next = new;
	new->prev = previous;
	return (new);
}
