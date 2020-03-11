/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:44:46 by hwolf             #+#    #+#             */
/*   Updated: 2019/06/11 19:01:26 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_set	*ft_set_cpy(t_set *src, t_set *dst)
{
	int		i;
	t_hash	hash;

	i = src->capacity;
	while (i--)
	{
		hash = src->hashtab[i];
		while (hash.value)
		{
			hash.index = hash.key % dst->capacity;
			ft_hash_insert(dst->hashtab, hash);
			dst->size++;
			if (hash.next)
				hash = *(hash.next);
			else
				break ;
		}
	}
	return (dst);
}

t_set			*ft_set_update(t_set *set)
{
	t_set	*newset;

	if (!(newset = ft_init_set(set->capacity * 2)))
		return (NULL);
	ft_set_cpy(set, newset);
	ft_set_destroy(&set);
	return (newset);
}

int				ft_set_insert(t_set **set, char *name)
{
	t_hash item;

	if (*set == NULL && !(*set = ft_init_set(INITHASHSIZE)))
		return (-1);
	if ((*set)->capacity * 3 < (*set)->size * 4)
		*set = ft_set_update(*set);
	item = ft_hash(name, (*set)->capacity);
	if (!ft_set_isexist(*set, item.key))
	{
		(*set)->size++;
		return (ft_hash_insert((*set)->hashtab, item));
	}
	return (0);
}

void			ft_set_destroy(t_set **set)
{
	if (set && *set)
	{
		ft_hash_destroy(&(*set)->hashtab, (*set)->capacity);
		ft_memdel((void**)set);
	}
}
