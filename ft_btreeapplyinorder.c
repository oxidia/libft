/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapplyinorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:36:16 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/25 16:36:38 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeapplyinorder(t_btree *root, void (*ft)(t_btree*))
{
	if (root == NULL)
		return ;
	ft_btreeapplypreorder(root->left, ft);
	(*ft)(root);
	ft_btreeapplypreorder(root->right, ft);
}
