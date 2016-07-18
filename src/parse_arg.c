/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:54:29 by telain            #+#    #+#             */
/*   Updated: 2016/07/18 20:32:05 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		parse_arg(int ac, char **av, t_data *d)
{
	if (ac == 1)
	{
		d->name = ".";
		return (0);
	}	
	else if (av[1][0] == '-')
	{
		while (av[d->cur_arg] && search_arg(av[d->cur_arg]) <= 1)
		{
			if (ft_strchr(av[d->cur_arg], 'l'))
				d->param = ft_strdup("l");
			if (ft_strchr(av[d->cur_arg], 'a'))
				d->param = ft_strcat(d->param, "a");
			d->cur_arg++;
		}
		put_error(1);
		return (0);
	}
	else
	{
		d->name = av[1];
		return (1);
	}
	return (0);
}

int		search_arg(char *av)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (av[++i])
	{
		if (av[i] == '-')
			c++;
	}
	return (c);
}
