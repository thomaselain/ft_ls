/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:54:29 by telain            #+#    #+#             */
/*   Updated: 2016/08/11 22:28:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		parse_arg(int ac, char **av, t_data *d)
{
	if (ac == 1)
	{
		d->name = ft_strdup("./");
		return (0);
	}
	else if (av[1][0] == '-')
	{
		if (!av[d->cur_arg])
			d->name = ft_strdup("./");
		else
		{
			d->name = ft_strjoin("./", av[d->cur_arg]);
			d->name = ft_strjoin(d->name, "/");
		}
	}
	else
	{
		if (av[d->cur_arg] && av[d->cur_arg][0] != '~')
			d->name = ft_strjoin("./", av[d->cur_arg]);
		d->name = ft_strjoin(av[d->cur_arg], "/");
		return (1);
	}
	if (av[d->cur_arg] && !ft_strchr(av[d->cur_arg], '~'))
		d->name = ft_strjoin(av[d->cur_arg], "/");		
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
		else if (av[0] == '-' && 
				av[i] != 'l' && av[i] != 'a' && av[i] != 'r' && av[i] != 'R'
				&& av[i] != 't' && av[i] != '-')
		{
			d->err_param = TRUE;
			return (-1);
		}
	}
	if (c > 1)
		d->err_param = TRUE;
	return (c);
}

void	find_param(t_data *d, char **av)
{
	while (av[d->cur_arg] && search_arg(av[d->cur_arg], d) == 1)
	{
		d->param = ft_strjoin(d->param, av[d->cur_arg]);
		d->cur_arg++;
	}
	if (d->err_param == TRUE)
	{
		put_error(ERR_USAGE, d->name);
		exit(0);
	}

}
