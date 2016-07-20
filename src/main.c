/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/07/20 17:39:55 by telain           ###   ########.fr       */
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
}

void	read_file(t_data *d)
{
	printf("\e[35mFOLDER we are curently in : \"%s\"\e[0m\n", d->name);
	if (!(d->dir = opendir(d->name)))
		put_error(ERR_NOFILE, d);
	ft_putstr("\n");
	while ((d->ent = readdir(d->dir)) != 0)
	{
		if (stat(d->ent->d_name, &(d->s)) != 0)
		{
			ft_putstr("ici\n");
			put_error(ERR_NOFILE, d);
		}
		d->pswd = getpwuid(d->s.st_uid);
		get_rights(d, &(d->s));
		if (d->ent->d_name[0] == '.' && !ft_strchr(d->param, 'a'))
			;
		else
		{
			ft_putstr(d->rights);
			ft_putstr("  ");
			if (d->s.st_nlink < 10)
				ft_putstr(" ");
			ft_putnbr(d->s.st_nlink);
			ft_putstr(" \t");
			ft_putstr(d->pswd->pw_name);
			ft_putstr("\t");
			ft_putnbr(d->s.st_size);
			ft_putstr("\t");
			ft_putstr(d->ent->d_name);
			ft_putstr("\n");
		}
		d->rights = ft_strdup("----------");
	}
	ft_putstr("\n");
	closedir(d->dir);
}
