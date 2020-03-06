/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:44:46 by hwolf             #+#    #+#             */
/*   Updated: 2019/06/11 19:01:26 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_heap	*ft_new_heap(void const *value, size_t key, size_t content_size)
{
	t_heap *new_heap;

	if (!(new_heap = (t_heap*)malloc(sizeof(*new_heap))))
		return (NULL);
	if (value)
	{
		if (!(new_heap->value = malloc(content_size)))
		{
			ft_memdel((void**)&new_heap);
			return (NULL);
		}
		ft_memcpy(new_heap->value, value, content_size);
	}
	else
		new_heap->value = NULL;
	new_heap->content_size = content_size;
	new_heap->key = key;
	new_heap->dist = 0;
	new_heap->left = NULL;
	new_heap->right = NULL;
	return (new_heap);
}

t_heap	*ft_wrap_heap(int key, void *value)
{
	t_heap *new_heap;

	if (!(new_heap = (t_heap*)malloc(sizeof(*new_heap))))
		return (NULL);
	new_heap->value = value;
	new_heap->content_size = 0;
	new_heap->key = key;
	new_heap->dist = 0;
	new_heap->left = NULL;
	new_heap->right = NULL;
	return (new_heap);
}
