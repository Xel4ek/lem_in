/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:07:21 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:09:22 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_forward_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_forward_list *ptr;

	if (!(ptr = (t_forward_list*)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content_size = content_size;
	if (content)
	{
		if (!(ptr->content = malloc(content_size)))
		{
			free(ptr);
			return (NULL);
		}
		ft_memcpy(ptr->content, content, content_size);
	}
	else
		ptr->content = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_list			*ft_lstdnew(void const *content, size_t content_size)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(*ptr))))
		return (NULL);
	if (content)
	{
		ptr->content_size = content_size;
		if (!(ptr->content = malloc(content_size)))
		{
			free(ptr);
			return (NULL);
		}
		ft_memcpy(ptr->content, content, content_size);
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	ptr->next = ptr;
	ptr->prev = ptr;
	return (ptr);
}

t_list			*ft_lstd_wrap(void *const content, size_t content_size)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = content;
	ptr->content_size = content_size;
	ptr->next = ptr;
	ptr->prev = ptr;
	return (ptr);
}
