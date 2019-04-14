/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:43:26 by ybahlaou          #+#    #+#             */
/*   Updated: 2018/10/29 16:45:29 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	size_t			newstr_len;
	unsigned int	i;

	newstr_len = ft_strlen(s);
	newstr = ft_strnew(newstr_len + 1);
	if (newstr != NULL)
	{
		i = 0;
		while (*(s + i))
		{
			*(newstr + i) = (*f)(i, *(s + i));
			i++;
		}
		*(newstr + i) = '\0';
	}
	return (newstr);
}
