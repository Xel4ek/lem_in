/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:37:10 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:22:18 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(const t_forward_list *list)
{
	int		len;

	len = 0;
	if (!list)
		return (0);
	while ((list = list->next))
		len++;
	return (len + 1);
}

int	ft_lstdlen(const t_list *list)
{
	int		len;
	t_list	*ptr;

	len = 0;
	ptr = NULL;
	if (list)
	{
		len++;
		if (list != list->next)
			while (list && list->next != ptr)
			{
				if (!ptr)
					ptr = (t_list*)list;
				list = list->next;
				len++;
			}
	}
	return (len);
}
