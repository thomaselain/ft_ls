/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:04:05 by cchicote          #+#    #+#             */
/*   Updated: 2016/05/07 17:31:39 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*new_struct(t_gnl *new)
{
	new = ft_memalloc(sizeof(t_gnl));
	new->str = ft_strnew(BUFF_SIZE + 1);
	new->buf[BUFF_SIZE] = '\0';
	new->start = 0;
	new->end = 0;
	return (new);
}

int			find_len(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start++] != '\n' && str[start] != '\0')
		i++;
	return (i);
}

int			find_bn(char *str, int start, int on)
{
	int index;

	index = 0;
	if (on == 1)
	{
		while (str[start] != '\0')
		{
			if (str[start] == '\n')
				return (start);
			start++;
		}
		return (-1);
	}
	else if (on == 0)
	{
		while (str[start++] != '\0')
			index++;
		return (index);
	}
	return (0);
}

int			sub_cpy(t_gnl *gnl, char **line, int ret)
{
	if (ret == 0)
	{
		*line = ft_strsub(gnl->str, gnl->start,
			find_bn(gnl->str, gnl->start, 0));
		gnl->end = 1;
		if (gnl->str[gnl->start - 1] == '\n'
			&& gnl->str[gnl->start] == '\0')
			return (0);
		return (1);
	}
	else
	{
		*line = ft_strsub(gnl->str, gnl->start,
			find_len(gnl->str, gnl->start));
		gnl->start = find_bn(gnl->str, gnl->start, 1) + 1;
		return (1);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	!gnl ? gnl = new_struct(gnl) : gnl;
	if (gnl->end == 1)
	{
		*line = ft_strnew(0);
		gnl ? ft_memdel((void*)&gnl) : gnl;
		return (0);
	}
	while (find_bn(gnl->str, gnl->start, 1) == -1 && ret > 0)
	{
		if ((ret = read(fd, gnl->buf, BUFF_SIZE)) == -1)
			return (-1);
		gnl->buf[ret] = '\0';
		gnl->str = ft_strjoin(gnl->str, gnl->buf);
	}
	if (sub_cpy(gnl, line, ret) == 0)
	{
		gnl ? ft_memdel((void*)&gnl) : gnl;
		return (0);
	}
	return (1);
}
