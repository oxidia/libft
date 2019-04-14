/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:28:51 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/02/15 18:19:15 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(t_list *a, t_list *b)
{
	t_list	tmp;

	tmp.content = a->content;
	tmp.content_size = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = tmp.content;
	b->content_size = tmp.content_size;
}

void		ft_lstsort(t_list *lst, int (*cmp)(void*, void*))
{
	t_list	*cur;

	while (lst != NULL)
	{
		cur = lst->next;
		while (cur != NULL)
		{
			if ((*cmp)(lst->content, cur->content) > 0)
				ft_swap(lst, cur);
			cur = cur->next;
		}
		lst = lst->next;
	}
}
