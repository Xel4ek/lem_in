/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:44:34 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:44:36 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int ft_get_next_pointer(t_mem *mem)
{
	if (!mem->current)
		mem->current = mem->head;
	else
	{
		*(mem->endl - 1) = '\n';
		mem->current = mem->endl;
	}
	if ((mem->endl = ft_strch(mem->current, '\n'))) {
		*mem->endl = 0;
		mem->endl++;
	}
	else
		return (0);
	return (1);
}
