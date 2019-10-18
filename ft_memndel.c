/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:26:39 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/10/18 10:45:49 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_array_del(void ***array)
{
	void	**iter;

	iter = *array;
	while (*iter != NULL)
	{
		ft_memdel(iter);
		iter++;
	}
	free(*array);
	*array = NULL;
}

void		ft_memndel(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'm')
				ft_memdel(va_arg(args, void**));
			else if (*format == 'a')
				ft_array_del(va_arg(args, void***));
		}
		format += *format != '\0';
	}
	va_end(args);
}
