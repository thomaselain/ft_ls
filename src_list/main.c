/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/07/22 16:50:04 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_data		d;

	data_init(&d);
	if (parse_arg(ac, av, &d) < 0)
		exit(0);
	ft_putstr("Used params : ");
	ft_putendl(d.param);
	read_file(&d);
	return (0);
}

void	data_init(t_data *d)
{
	d->rights = ft_strdup("----------");
	d->cur_arg = 1;
	d->name = ft_strnew(1);
	d->param = ft_strnew(1);
	new_list(d);
}

void	read_file(t_data *d)
{
	t_file		*file;

	file = new_file(NULL, "", "");
	*d->begin = file;
	printf("\e[35mFOLDER we are curently in : \"%s\"\e[0m\n", d->name);
	if (!(d->dir = opendir(d->name)))
		put_error(ERR_NOFILE, d);
	while ((d->ent = readdir(d->dir)) != 0)
	{
		stat(d->ent->d_name, &(d->s));
		d->pswd = getpwuid(d->s.st_uid);
		d->grp = getgrgid(d->s.st_uid);
		if (stat(d->name, &(d->s)) != 0)
			put_error(ERR_NOFILE, d);
		file->next = new_file(file, d->ent->d_name,
				ft_strsub(ctime(&(d->s.st_mtimespec.tv_sec)), 4, 12));
		ft_putendl(file->date);
		ft_putstr("\t");
		ft_putstr(file->name);
		file = file->next;
	}
	closedir(d->dir);
}
