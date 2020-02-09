/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:39:51 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/18 22:19:08 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_forward_list	*ft_lstappend(t_forward_list *head, t_forward_list *new)
{
	t_forward_list *ptr;

	ptr = head;
	if (new && head)
		if (head)
		{
			while ((head)->next)
				head = (head)->next;
			(head)->next = new;
			return (ptr);
		}
	return (new);
}
