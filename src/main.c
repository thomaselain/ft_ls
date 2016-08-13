/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/08/13 15:24:24 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_data		d;

	data_init(&d);
	while (d.cur_arg < ac || (d.cur_arg == ac && ac == 1))
	{
		find_param(&d, av);
		parse_arg(ac, av, &d);
		read_file(&d, av);
	}
	return (0);
}

void	data_init(t_data *d)
{
	d->rights = ft_strdup("----------");
	d->cur_arg = 1;
	d->name = ft_strnew(1);
	d->param = ft_strnew(1);
	d->err_param = FALSE;
	d->file_arg = FALSE;
	new_list(d);
}

int		read_file(t_data *d, char **av)
{
	t_file		*file;

	d->file_arg = FALSE;
	d->displayed = FALSE;
	if (!(d->dir = opendir(d->name)))
	{
		d->dir = opendir("./");
		d->name = av[d->cur_arg];
		d->file_arg = TRUE;
	}
	*d->begin = new_file(NULL, d, d->name);
	file = *d->begin;
	while ((d->ent = readdir(d->dir)) != 0)
	{
		file->next = new_file(file, d, d->ent->d_name);
		file = file->next;
	}
	d->biggest = 1;
	d->biggest = find_biggest_size(d);
	sort_list(d, *d->begin, 1);
	if (ft_strchr(d->param, 't'))
		sort_list_time(d, *d->begin, 1);
	file = *d->begin;
	file = file->next;
	if (ft_strchr(d->param, 'R'))
	{
		recursive(d, file);
		return (0);
	}
	else
		display_folder(d, file);
	closedir(d->dir);
	return (0);
}
