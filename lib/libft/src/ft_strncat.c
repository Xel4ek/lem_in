/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:08:16 by hwolf             #+#    #+#             */
/*   Updated: 2019/06/11 19:42:06 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *tmp;

	tmp = dst;
	while (*dst)
		++dst;
	while (*src && n--)
		*(dst++) = *(src++);
	*dst = 0;
	return (tmp);
}
