/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:34:19 by telain            #+#    #+#             */
/*   Updated: 2016/08/11 22:27:41 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	display_infos(t_file *f, t_data *d)
{
	if (f->file_name[0] == '.' && !ft_strchr(d->param, 'a'))
		;
	else
	{
		ft_putstr(f->rights);
		ft_putstr("  ");
		if (f->links < 10)
			ft_putstr(" ");
		ft_putnbr(f->links);
		ft_putstr(" ");
		ft_putstr(f->usr_name);
		ft_putstr("  ");
		ft_putstr(f->grp_name);
		put_n_spaces(d->biggest - ft_strlen(ft_itoa(f->size)) + 2);
		ft_putnbr(f->size);
		ft_putstr(" ");
		ft_putstr(f->date);
		ft_putstr(" ");
		ft_putstr(f->file_name);
		ft_putstr("\n");
	}
}

void	put_n_spaces(int n)
{
	int		i;

	i = -1;
	while (++i < n)
		ft_putchar(' ');
}

int		find_biggest_size(t_data *d)
{
	t_file	*f;
	int		biggest;

	biggest = 0;
	f = *d->begin;
	while (f->next)
	{
		if ((size_t)biggest < ft_strlen(ft_itoa(f->size)))
			biggest = ft_strlen(ft_itoa(f->size));
		f = f->next;
	}
	return (biggest);
}
