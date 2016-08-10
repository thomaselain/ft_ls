/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/08/10 15:16:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_data		d;

	data_init(&d);
	if (parse_arg(ac, av, &d) < 0)
		exit(0);
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

	ft_putnendl(d->cur_arg);
	d->cur_arg++;
	ft_putstr(d->name);
	ft_putendl(" :");
	if (!(d->dir = opendir(d->name)))
		put_error(ERR_NOFILE, d->name);
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
	file = *d->begin;
	file = file->next;
	while (file)
	{
		display_infos(file, d);
		file = file->next;
	}
	ft_putstr("Cur_arg : ");
	ft_putnendl(d->cur_arg);
	ft_putstr("\n\n");
	d->cur_arg++;
	closedir(d->dir);
}
