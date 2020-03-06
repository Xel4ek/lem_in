/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:19:09 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:20:04 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_del(t_list **hash_table, unsigned size)
{
	while (size--)
		ft_lstd_del(&hash_table[size]);
}

void	ft_hash_del_2(t_hash **hash_tab, size_t size)
{
	t_hash *item;

	while (size--)
	{
		item = (*hash_tab)[size].next;
		while (item)
		{
			ft_memdel((void **)&item);
			item = item->next;
		}
	}
	ft_memdel((void**)hash_tab);
}
