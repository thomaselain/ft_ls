/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:01:35 by telain            #+#    #+#             */
/*   Updated: 2016/08/06 16:22:10 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_error(int err, char *file)
{
	if (err == ERR_NOFILE)
	{
		ft_putstr("\e[31merror\e[0m : \"");
		ft_putstr(file);
		ft_putendl("\" No such file or directory");
	}
	else if (err == ERR_USAGE)
		ft_putendl("\e[32mUsage\e[0m : ./ft_ls [-la] [File_name]");
	else if (err == ERR_NORIGHT)
	{
		ft_putstr("\"");
		ft_putstr(file);
		ft_putendl("\" Permission denied");
	}
	exit(0);
}
