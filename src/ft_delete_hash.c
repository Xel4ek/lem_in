/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:42:59 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:43:02 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int 	ft_delete_edge_hash(t_hash **edge_hash, int res)
{
	int i;
	t_hash	*temp;
	t_hash	*ptr;

	i = HASH_SIZE;
	while (i)
	{
		temp = edge_hash[--i];
		while (temp)
		{
			ptr = temp->next;
			ft_memdel(&(temp->content));
			free(temp);
			temp = ptr;
		}
	}
	free(edge_hash);
	return (res);
}

int 	ft_delete_hashtab(t_hash **hashtab, int res)
{
	int i;
	t_hash	*temp;
	t_hash	*ptr;

	i = HASH_SIZE;
	while (i)
	{
		temp = hashtab[--i];
		while (temp)
		{
			ptr = temp->next;
			temp->content = NULL;
			free(temp);
			temp = ptr;
		}
	}
	free(hashtab);
	return (res);
}

int 	ft_delete_coord_hash(t_hash **hashtab, int res)
{
	int i;
	t_hash	*temp;
	t_hash	*ptr;

	i = HASH_SIZE;
	while (i)
	{
		temp = hashtab[--i];
		while (temp)
		{
			ptr = temp->next;
			ft_memdel(&(temp->cmp_ptr));
			free(temp);
			temp = ptr;
		}
	}
	free(hashtab);
	return (res);
}
