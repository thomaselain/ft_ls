/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:01:35 by telain            #+#    #+#             */
/*   Updated: 2016/07/18 20:32:31 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_error(int err)
{
	if (err == -1)
		ft_putendl("\e[31merror\e[0m : This file or directory doesn't exist");
	else if (err == 1)
		ft_putendl("\e[32mUsage\e[0m : ./ft_ls [-la] [File_name]");
	exit(0);
}
