/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:44:46 by hwolf             #+#    #+#             */
/*   Updated: 2019/06/11 19:01:26 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_set	*ft_init_set(size_t size)
{
	t_set *set;

	if (!(set = (t_set*)malloc(sizeof(*set))))
		return (NULL);
	set->hashtab = ft_hash_init(size);
	set->size = 0;
	set->capacity = size;
	return (set);
}

void	*ft_set_isexist(t_set *set, size_t key)
{
	t_hash *item;
	size_t index;

	index = key % set->capacity;
	if ((item = &set->hashtab[index])->value)
		while (item)
		{
			if (item->key == key)
				return (item->value);
			item = item->next;
		}
	return (NULL);
}

void	*ft_set_get_value(t_set *set, char *value)
{
	return (ft_set_isexist(set, ft_hash(value, set->capacity).key));
}
