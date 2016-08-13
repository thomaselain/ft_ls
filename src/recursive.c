/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 13:48:36 by telain            #+#    #+#             */
/*   Updated: 2016/08/13 15:23:37 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		recursive(t_data *d, DIR *dir)
{
	while (folder->next)
	{
		if (folder->rights[0] == 'd')
		{
			d->name = folder->file_name;
			ft_putendl(d->name);
			display_folder(d, folder);
			recursive(d, folder->next);
		}
		else
			folder = folder->next;
	}
	return (0);
}
