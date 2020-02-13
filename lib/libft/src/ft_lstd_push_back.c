/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:16:27 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:22:29 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_back(t_list **head, t_list *new)
{
	if (head && new && *head)
	{
		new->next = *head;
		new->prev = (*head)->prev;
		new->next->prev = new;
		new->prev->next = new;
	}
	else
		*head = new;
}
