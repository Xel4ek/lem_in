/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:24:59 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 17:45:48 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *ptr;

	ptr = dst;
	dst += ft_strlen(dst);
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
	return (ptr);
}

char	*ft_strcat_end(char *dst, const char *src)
{
	while (*dst)
		++dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = 0;
	return (dst);
}
