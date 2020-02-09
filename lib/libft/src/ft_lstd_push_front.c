/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:15:15 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:15:25 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_front(t_list **head, t_list *new)
{
	if (head && new)
	{
		if (*head)
		{
			new->next = *head;
			new->prev = (*head)->prev;
			if ((*head)->prev)
				(*head)->prev->next = new;
			*head = new;
			(*head)->next->prev = *head;
		}
		else
			*head = new;
	}
}
