/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_collapse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:57 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:17:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_collapse(t_list *head)
{
	t_list *ptr;

	ptr = NULL;
	if (head && head->next)
	{
		while (head->next && head != ptr)
		{
			if (!ptr)
				ptr = head;
			head = head->next;
		}
		head->next = ptr;
		head->next->prev = head;
	}
	else if (head)
	{
		head->next = head;
		head->next->prev = head;
	}
}
