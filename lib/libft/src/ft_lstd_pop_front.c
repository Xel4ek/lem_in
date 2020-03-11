/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:15:50 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:22:36 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pop_front(t_list **head)
{
	t_list *ptr;

	if (head && *head)
	{
		ptr = *head;
		if (ptr != (*head)->next)
			ptr = (*head)->next;
		else
			ptr = NULL;
		if (ptr != NULL)
		{
			ptr->prev = ptr->prev->prev;
			ptr->prev->next = ptr;
		}
		ft_memdel(&((*head)->content));
		ft_memdel((void**)head);
		(*head) = ptr;
	}
}

void	ft_lstd_pop_front_head_only(t_list **head)
{
	t_list *ptr;

	if (head && *head)
	{
		ptr = *head;
		if (ptr != (*head)->next)
			ptr = (*head)->next;
		else
			ptr = NULL;
		if (ptr != NULL)
		{
			ptr->prev = ptr->prev->prev;
			ptr->prev->next = ptr;
		}
		ft_memdel((void**)head);
		(*head) = ptr;
	}
}
