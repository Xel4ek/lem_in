/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:47 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:48 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_mem	*ft_init_memory(void)
{
	t_mem *memory;

	if (!(memory = (t_mem *)malloc(sizeof(*memory))))
		return (NULL);
	memory->size = START_MEMORY_SIZE;
	if (!(memory->head = (char *)malloc(sizeof(char) * (memory->size + 1))))
	{
		ft_memdel((void **)&memory);
		return (NULL);
	}
	memory->current = memory->head;
	memory->end = memory->current;
	(*memory->current) = 0;
	return (memory);
}
