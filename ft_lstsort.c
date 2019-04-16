/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:28:51 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/16 03:16:05 by ussef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_quicksort(t_list	*lst, int size, int (*cmp)(void*, void*));

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

#include <stdio.h>

void	ft_p(t_list *elm)
{
	int	*ptr;

	ptr = (int*)elm->content;
	printf("%d ", *ptr);
}

static void	ft_part(t_list *lst, int left, int right, int (*cmp)(void*, void*))
{
	static int	depth = 0;
	t_list	*pivot;
	t_list	*i;
	t_list	*j;
	int		i_c;
	int		j_c;

	depth++;
	if (left >= right)
		return ;
	i = lst;
	i_c = -1;
	j = ft_lstget(lst, left);
	j_c = left;
	pivot = ft_lstget(lst, right);
	while (j_c < right)
	{
		printf("depth: %d, i: %p, j: %p\n", depth, i, j);
		ft_lstiter(lst, &ft_p);
		printf("\n");
		if (cmp(j, pivot) < 0)
		{
			if (i_c >= 0)
				i = i->next;
			i_c++;
			ft_swap(j, i);
		}
		j = j->next;
		j_c++;
	}
	ft_swap(i->next, pivot);
	ft_lstiter(lst, &ft_p);
	printf("\n");
	ft_quicksort(lst, i_c + 1, cmp);
	ft_quicksort(i->next, right - i_c, cmp);
	depth--;
}

static void	ft_quicksort(t_list	*lst, int size, int (*cmp)(void*, void*))
{
	if (size <= 0)
		return ;
	ft_part(lst, 0, size - 1, cmp);
}

void		ft_lstsort(t_list *lst, int (*cmp)(void*, void*))
{
	ft_quicksort(lst, (int)ft_lstsize(lst), cmp);
	return ;
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
