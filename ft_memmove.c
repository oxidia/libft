/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:30:30 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/10 10:09:02 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;

	dst_tmp = (unsigned char*)malloc(sizeof(unsigned char) * len);
	if (dst_tmp == NULL)
		return (NULL);
	ft_memcpy(dst_tmp, src, len);
	ft_memcpy(dst, dst_tmp, len);
	free(dst_tmp);
	return (dst);
}
