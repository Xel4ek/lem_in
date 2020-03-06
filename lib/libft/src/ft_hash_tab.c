/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:15:50 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:22:36 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash	*ft_hash_init(size_t size)
{
	t_hash	*hash_tab;
	size_t	i;

	if (!(hash_tab = (t_hash*)malloc(sizeof(t_hash) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		(hash_tab)[i].value = NULL;
		(hash_tab)[i++].next = NULL;
	}
	return (hash_tab);
}

int		ft_hash_insert(t_hash *hash_tab, t_hash new)
{
	t_hash	*new_list;
	size_t	index;

	index = new.index;
	if (hash_tab[index].value == NULL)
	{
		hash_tab[index].key = new.key;
		hash_tab[index].index = new.index;
		hash_tab[index].value = new.value;
		hash_tab[index].next = NULL;
		return (1);
	}
	if (!(new_list = (t_hash*)malloc(sizeof(*new_list))))
		return (0);
	new_list->key = new.key;
	new_list->index = new.index;
	new_list->value = new.value;
	new_list->next = hash_tab[index].next;
	hash_tab[index].next = new_list;
	return (1);
}
