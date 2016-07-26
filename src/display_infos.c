/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:34:19 by telain            #+#    #+#             */
/*   Updated: 2016/07/26 15:13:17 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display_infos(t_file *f, t_data *d)
{
	ft_putstr(f->rights);
	ft_putstr(" ");
	ft_putnbr(f->links);
	ft_putstr(" ");
	ft_putstr(f->usr_name);
	ft_putstr("\t");
	ft_putstr(f->grp_name);
	ft_putstr("\t");
	ft_putnbr(f->size);
	ft_putstr(" ");
	ft_putstr(f->date);
	ft_putstr(" ");
	ft_putstr(f->file_name);
	ft_putstr("\n");
	if (d)
		;
}
