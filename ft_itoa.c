/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:43:59 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/31 12:20:51 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + ft_nbrlen(n / 10));
}

char		*ft_itoa(int nbr)
{
	char			*str;
	int				nbrlen;
	int				sign;

	sign = nbr < 0;
	nbrlen = ft_nbrlen(nbr) + sign;
	if (!(str = ft_strnew(nbrlen)))
		return (NULL);
	if (sign == 1)
		*str = '-';
	*(str + nbrlen) = '\0';
	while (nbrlen > sign)
	{
		if (nbr >= 0)
			*(str + --nbrlen) = nbr % 10 + '0';
		else
			*(str + --nbrlen) = -(nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
