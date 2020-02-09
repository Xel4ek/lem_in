/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:15:48 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:35:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != (char)c)
	{
		if (!*ptr)
			return (NULL);
		++ptr;
	}
	return (ptr);
}

char	*ft_strch(const char *str, int ch)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != (char)ch && *ptr)
		++ptr;
	return (ptr);
}
