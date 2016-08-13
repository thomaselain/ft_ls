/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_folder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 14:49:56 by telain            #+#    #+#             */
/*   Updated: 2016/08/13 15:21:59 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display_folder(t_data *d, t_file *file)
{
	file = *d->begin;
	file = file->next;
	if (d->file_arg == FALSE)
	{
		ft_putstr(d->name);
		ft_putstr(" :\n");
	}
	while (file)
	{
		if (!ft_strcmp(file->file_name, d->name))
		{
			if (d->file_arg == TRUE)
				display_infos(file, d);
			else
			{
				d->cur_arg++;
				put_error(ERR_NOFILE, d->name);
			}
		}
		else if (d->file_arg == FALSE)
			display_infos(file, d);
		file = file->next;
	}
	if (d->displayed == FALSE)
		put_error(ERR_NOFILE, d->name);
	ft_putstr("\n");
	d->cur_arg++;
}
