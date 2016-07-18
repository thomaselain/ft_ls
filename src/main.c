/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/07/18 20:30:48 by telain           ###   ########.fr       */
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
	d->cur_arg = 1;
	d->param = ft_strnew(1);
}

void	read_file(t_data *d)
{
	if (!(d->dir = opendir(d->name)))
		put_error(-1);
	while ((d->ent = readdir(d->dir)) != 0)
	{
		stat(d->ent->d_name, &(d->s));
		d->pswd = *getpwuid(d->s.st_uid);
		if (d->ent->d_name[0] != '.' && !ft_strchr(d->param, 'a'))
		{
			ft_putstr(d->pswd.pw_name);
			ft_putstr("\t");
			ft_putstr(d->pswd.pw_shell);
			ft_putstr("\t");
			ft_putstr(d->ent->d_name);
			ft_putstr("\n");
		}
	}
	closedir(d->dir);
}
