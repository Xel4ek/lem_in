/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:18:27 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:18:54 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_hash_old(const char *string, \
				unsigned int size)
{
	unsigned long int	hash;

	hash = 0;
	if (string)
		while (*string)
			hash = hash * 53 + *string++ - 31;
	return (hash % size);
}

t_hash			ft_hash(const char *string, unsigned int size)
{
	t_hash				hash;
	unsigned long int	key;

	key = 0;
	hash.value = (void*)string;
	if (string)
		while (*string)
			key = key * 53 + *string++ - 31;
	hash.key = key;
	hash.index = key % size;
	hash.next = NULL;
	return (hash);
}

void			ft_hash_destroy(t_hash **hashtab, size_t size)
{
	t_hash	*hash;
	t_hash	*keep;

	while (size--)
	{
		hash = ((*hashtab) + size)->next;
		while (hash)
		{
			keep = hash->next;
			ft_memdel((void**)&hash);
			hash = keep;
		}
	}
	ft_memdel((void**)hashtab);
}

unsigned int	ft_hash_int(const int *tab,
			unsigned int len, const unsigned int size)
{
	unsigned int	hash;

	hash = 0;
	if (tab)
		while (len--)
			hash = hash * 17 + tab[len] + 2;
	return (hash % size);
}
