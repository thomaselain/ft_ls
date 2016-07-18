/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:25:50 by telain            #+#    #+#             */
/*   Updated: 2016/06/23 14:26:13 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int v, int base)
{
	int		length;
	int		sign;
	int		bck;
	char	*ret;

	bck = v;
	length = 1;
	sign = v < 0 ? 1 : 0;
	if (base != 10)
		sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	while (bck /= base)
		length++;
	if (!(ret = (char *)malloc(sizeof(char) * length + sign + 1)))
		return (NULL);
	ret[length + sign] = '\0';
	ret[0] = '-';
	while (length--)
	{
		ret[length + sign] = v < 0 ? (-(v % -(base))) + 48 : (v % base) + 48;
		ret[length + sign] += ret[length + sign] > 57 ? 7 : 0;
		v /= base;
	}
	return (ret);
}
