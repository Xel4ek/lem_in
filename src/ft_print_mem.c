/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:48:32 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:48:34 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_mem(t_mem **mem)
{
	int	i;
	int	len;
	ft_printf("%s\n", (*mem)->head);

//	(*mem)->current = (*mem)->head;
//	i = ft_strlen((*mem)->current);
//	len = 0;
//	while (i)
//	{
//		(*mem)->current[i] = '\n';
//		(*mem)->current += i + 1;
//		len += i;
//		i = ft_strlen((*mem)->current);
//	}
//	ft_printf ("%s\n", (*mem)->head);
//	ft_memdel((void **)&(*mem)->head);
//	ft_memdel((void **)mem);
}
