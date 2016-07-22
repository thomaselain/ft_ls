/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:54:29 by telain            #+#    #+#             */
/*   Updated: 2016/07/22 13:30:11 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		parse_arg(int ac, char **av, t_data *d)
{
	char	*tmp;

	tmp = ft_strdup("./");
	if (ac == 1)
	{
		d->name = ft_strdup("./");
		return (0);
	}	
	else if (av[1][0] == '-')
	{
		while (av[d->cur_arg] && search_arg(av[d->cur_arg], d) == 1)
		{
			if (ft_strchr(av[d->cur_arg], 'l'))
				d->param = ft_strcat(d->param, "l");
			if (ft_strchr(av[d->cur_arg], 'a'))
				d->param = ft_strcat(d->param, "a");
			if (ft_strchr(av[d->cur_arg], 'R'))
				d->param = ft_strcat(d->param, "R");
			if (ft_strchr(av[d->cur_arg], 'r'))
				d->param = ft_strcat(d->param, "r");
			if (ft_strchr(av[d->cur_arg], 't'))
				d->param = ft_strcat(d->param, "t");
			d->cur_arg++;
		}
		if (!av[d->cur_arg])
			d->name = ft_strdup("./");
		else
			d->name = ft_strjoin("./", av[d->cur_arg]);
		return (0);
	}
	else
	{
		ft_putstr("Ici\n");
		d->name = ft_strjoin("./", av[1]);
		return (1);
	}
	return (0);
}

int		search_arg(char *av, t_data *d)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (av[++i])
	{
		if (av[i] == '-' && av[i + 1])
			c++;
	}
	if (c > 1)
		put_error(ERR_USAGE, d);
	return (c);
}