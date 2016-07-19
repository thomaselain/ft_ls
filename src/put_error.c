/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:01:35 by telain            #+#    #+#             */
/*   Updated: 2016/07/19 19:47:28 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_error(int err, t_data *d)
{
	if (err == -1)
	{
		ft_putstr("\e[31merror\e[0m : \"");
		ft_putstr(d->name);
		ft_putendl("\" No such file or directory");
	}
	else if (err == 1)
		ft_putendl("\e[32mUsage\e[0m : ./ft_ls [-la] [File_name]");
	else if (err == 2)
	{
		ft_putstr("\e[31merror\e[0m : \"");
		ft_putstr(d->name);
		ft_putendl("\" Permission denied");
	}
	exit(0);
}
