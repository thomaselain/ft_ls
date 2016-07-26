/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/07/26 15:08:02 by telain           ###   ########.fr       */
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

	ft_putstr(d->name);
	ft_putendl(" :");
	if (!(d->dir = opendir(d->name)))
	{
		ft_putstr("Coucou\n");
		put_error(ERR_NOFILE, d->name);
	}
	file = new_file(NULL, d, d->name);
//	*d->begin = file;    Pour la recursive (revenir au debut de la liste)
	while ((d->ent = readdir(d->dir)) != 0)
	{
		file->next = new_file(file, d, d->ent->d_name);
		if (file->next->file_name[0] == '.' && !ft_strchr(d->param, 'a'))
			;
		else
			display_infos(file->next, d);
		file = file->next;
	}
	closedir(d->dir);
}
