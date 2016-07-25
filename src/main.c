/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 16:23:17 by telain            #+#    #+#             */
/*   Updated: 2016/07/25 19:29:56 by telain           ###   ########.fr       */
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

	printf("\e[35mFOLDER we are curently in : \"%s\"\e[0m\n", d->name);
	if (!(d->dir = opendir(d->name)))
	{
		ft_putstr("Coucou\n");
		put_error(ERR_NOFILE, d->name);
	}
	file = new_file(NULL, d, d->name);
//	*d->begin = file;
	while ((d->ent = readdir(d->dir)) != 0)
	{
		file->next = new_file(file, d, d->ent->d_name);
		if (file->next->file_name[ft_strlen(d->name)] == '.' && !ft_strchr(d->param, 'a'))
			;
		else
			display_infos(file->next);
		file = file->next;
	}
	closedir(d->dir);
}
