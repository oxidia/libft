/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:45:42 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 15:30:09 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	bytes_size;
	size_t	i;
	size_t	dest_size;

	dest_size = ft_strlen(dst);
	bytes_size = 0;
	if (size > dest_size)
		bytes_size = size - dest_size - 1;
	i = 0;
	while (i < bytes_size && *(src + i))
	{
		*(dst + dest_size + i) = *(src + i);
		i++;
	}
	*(dst + dest_size + i) = '\0';
	if (size >= dest_size)
		return (dest_size + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
