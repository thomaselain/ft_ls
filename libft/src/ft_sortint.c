/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:21:25 by telain            #+#    #+#             */
/*   Updated: 2016/07/21 16:55:09 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_sortint(int *tab)
{
	int		tmp;
	int		len;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	len--;
	len = i;
	i = 0;
	while (len-- > 0)
	{
		while (tab[i + 1])
		{
			if (tab[i] < tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
	}
	return (tab);
}
