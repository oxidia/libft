/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:51:14 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/03/13 15:51:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, size_t index)
{
	while (lst != NULL)
	{
		if (index-- == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
