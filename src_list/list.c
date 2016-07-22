/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:41:00 by telain            #+#    #+#             */
/*   Updated: 2016/07/22 16:50:03 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	new_list(t_data *d)
{
	d->begin = ft_memalloc(sizeof(struct s_list**));
}

t_file	*new_file(t_file *previous, char *name, char *date)
{
	t_file		*new;

	new = ft_memalloc(sizeof(struct s_file*));
	new->name = ft_strdup(name);
	new->date =	ft_strdup(date);
	new->right = 1;
	new->next = NULL;
	if (previous)
		previous->next = new;
	new->prev = previous;
	return (new);
}
