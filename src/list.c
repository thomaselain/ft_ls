/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:41:00 by telain            #+#    #+#             */
/*   Updated: 2016/08/06 17:39:39 by telain           ###   ########.fr       */
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
	new->path = ft_strjoin(d->name, new->path);
	if (ft_strcmp(new->path, str) && !ft_strchr(d->name, '~'))
		new->path = ft_strjoin(d->name, str);
	if (stat(new->path, &s) != 0)
		put_error(ERR_NOFILE, new->path);
	pswd = getpwuid(s.st_uid);
	grp = getgrgid(s.st_gid);
	get_rights(new, &s);
	new->date = ft_strsub(ctime(&(s.st_mtimespec.tv_sec)), 4, 12);
	new->links = s.st_nlink;
	new->size = s.st_size;
	new->grp_name = grp->gr_name;
	new->usr_name = pswd->pw_name;
	new->file_name = ft_strdup(str);
	new->next = NULL;
	if (previous)
		previous->next = new;
	new->prev = previous;
	return (new);
}

void	sort_list(t_data *d, t_file *first, int i)
{
	t_file	*tmp;
	t_file	*begin;
	int		rev;

	begin = first;
	rev = (ft_strchr(d->param, 'r')) ? -1 : 1;
	while (i == 1)
	{
		i = 0;
		while (first->next->next)
		{
			if (ft_strcmp(first->next->file_name,
						first->next->next->file_name) * rev > 0)
			{
				tmp = first->next;
				first->next = first->next->next;
				tmp->next = first->next->next;
				first->next->next = tmp;
				i = 1;
			}
			first = first->next;
		}
		first = begin;
	}
}
