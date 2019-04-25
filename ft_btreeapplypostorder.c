/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeapplypostorder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:37:31 by ybahlaou          #+#    #+#             */
/*   Updated: 2019/04/25 16:37:59 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeapplypostorder(t_btree *root, void (*ft)(t_btree*))
{
	if (root == NULL)
		return ;
	ft_btreeapplypreorder(root->left, ft);
	ft_btreeapplypreorder(root->right, ft);
	(*ft)(root);
}
