/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:41:00 by telain            #+#    #+#             */
/*   Updated: 2016/08/13 15:16:30 by telain           ###   ########.fr       */
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
	if (stat(new->path, &s) != 0 && d->file_arg == FALSE)
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
	t_file	*begin;
	int		rev;

	rev = (!ft_strchr(d->param, 'r')) ? 1 : -1;
	begin = first;
	while (i == 1)
	{
		i = 0;
		while (first->next->next)
		{
			if (ft_strcmp(first->next->file_name,
						first->next->next->file_name) * rev > 0)
			{
				swap_files(first);
				i = 1;
			}
			first = first->next;
		}
		first = begin;
	}
}

void	sort_list_time(t_data *d, t_file *first, int i)
{
	t_file	*begin;
	int		rev;

	rev = (!ft_strchr(d->param, 'r')) ? 1 : -1;
	begin = first;
	while (i == 1)
	{
		i = 0;
		while (first->next->next)
		{
			if (date_cmp(first->next->date, first->next->next->date) * rev > 0)
			{
				swap_files(first);
				i = 1;
			}
			first = first->next;
		}
		first = begin;
	}
}

void	swap_files(t_file *file)
{
	t_file	*tmp;

	tmp = file->next;
	file->next = file->next->next;
	tmp->next = file->next->next;
	file->next->next = tmp;
}

int		date_cmp(char *date1, char *date2)
{
	int		d1;
	int		d2;

	d1 = 0;
	d2 = 0;
	d1 += find_month(ft_strsub(date1, 0, 3)) * 86400 * 30
		+ ft_atoi(ft_strsub(date1, 4, 2)) * 86400
		+ ft_atoi(ft_strsub(date1, 7, 2)) * 3600
		+ ft_atoi(ft_strsub(date1, 10, 2)) * 60;
	d2 += find_month(ft_strsub(date2, 0, 3)) * 86400 * 30
		+ ft_atoi(ft_strsub(date2, 4, 2)) * 86400
		+ ft_atoi(ft_strsub(date2, 7, 2)) * 3600
		+ ft_atoi(ft_strsub(date2, 10, 2)) * 60;
	return (d2 - d1);
}

int		find_month(char *date)
{
	if ((!ft_strcmp(date, "Jan")))
		return (1);
	else if ((!ft_strcmp(date, "Feb")))
		return (2);
	else if ((!ft_strcmp(date, "Mar")))
		return (3);
	else if ((!ft_strcmp(date, "Apr")))
		return (4);
	else if ((!ft_strcmp(date, "May")))
		return (5);
	else if ((!ft_strcmp(date, "Jun")))
		return (6);
	else if ((!ft_strcmp(date, "Jul")))
		return (7);
	else if ((!ft_strcmp(date, "Aug")))
		return (8);
	else if ((!ft_strcmp(date, "Sep")))
		return (9);
	else if ((!ft_strcmp(date, "Oct")))
		return (10);
	else if ((!ft_strcmp(date, "Nov")))
		return (11);
	else
		return (12);
}
