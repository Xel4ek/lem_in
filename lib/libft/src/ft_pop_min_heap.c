/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_min_heap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:44:46 by hwolf             #+#    #+#             */
/*   Updated: 2019/06/11 19:01:26 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pop_min_heap(t_heap **heap, int *key)
{
	void	*item;
	t_heap	*new_heap;

	if (!heap || !*heap)
		return (NULL);
	item = (*heap)->value;
	*key = (*heap)->key;
	new_heap = ft_heap_merge((*heap)->left, (*heap)->right);
	ft_memdel((void**)heap);
	(*heap) = new_heap;
	return (item);
}
