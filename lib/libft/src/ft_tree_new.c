/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:31:35 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:31:52 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_tree	*ft_tree_new(void const *content, size_t content_size)
{
	t_tree *new_tree;

	if (!(new_tree = (t_tree*)malloc(sizeof(*new_tree))))
		return (NULL);
	if (content)
	{
		new_tree->content_size = content_size;
		if (!(new_tree->content = malloc(content_size)))
		{
			ft_memdel((void**)&new_tree);
			return (NULL);
		}
		ft_memcpy(new_tree->content, content, content_size);
	}
	{
		new_tree->content = NULL;
		new_tree->content_size = 0;
	}
	new_tree->left = NULL;
	new_tree->right = NULL;
	return (new_tree);
}
