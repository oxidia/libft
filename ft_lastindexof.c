/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastindexof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:52:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/03/13 15:52:32 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_lastindexof(const char *str, char c)
{
	ssize_t	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (*(str + i) == c)
			return (i);
		i--;
	}
	return (-1);
}
