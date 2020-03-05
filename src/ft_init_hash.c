/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:39 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:41 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_hash_old	**ft_init_hash(int size)
{
	t_hash_old	**hashtab;

	if (!(hashtab = (t_hash_old **)malloc(sizeof(t_hash_old *) * size)))
		return (NULL);
	while (size--)
		hashtab[size] = NULL;
	return (hashtab);
}
