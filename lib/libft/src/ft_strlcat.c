/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:51:33 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:15:42 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	tmp;
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		++len;
	tmp = len;
	while (src[len - tmp] && len + 1 < size)
	{
		dst[len] = src[len - tmp];
		++len;
	}
	if (tmp < size)
		dst[len] = 0;
	return (tmp + ft_strlen(src));
}
