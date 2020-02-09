/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:59:52 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:14:16 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_forward_list	*ft_lstmap(t_forward_list *lst,
							t_forward_list *(*f)(t_forward_list *elem))
{
	t_forward_list		*ans;
	t_forward_list		*ptr;

	if (lst && (*f))
	{
		ptr = f(lst);
		ans = ptr;
		while (lst->next)
		{
			lst = lst->next;
			if (!(ptr->next = f(lst)))
			{
				free(ptr->next);
				return (NULL);
			}
			ptr = ptr->next;
		}
		return (ans);
	}
	return (NULL);
}
