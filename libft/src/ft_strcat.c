/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:25:45 by telain            #+#    #+#             */
/*   Updated: 2016/07/20 17:15:54 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *str, const char *str2)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (str[i])
		i++;
	while (str2[i2])
		str[i++] = str2[i2++];
	str[i] = '\0';
	return (str);
}
