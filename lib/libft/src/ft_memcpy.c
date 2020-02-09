/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:56:40 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:03:19 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	long			*dst_ptr;
	long			*src_ptr;
	unsigned char	*dst_ptr_char;
	unsigned char	*src_ptr_char;
	size_t			long_len;

	dst_ptr = (long*)dst;
	src_ptr = (long*)src;
	long_len = sizeof(*dst_ptr);
	if ((dst == src) || !n)
		return (dst);
	while (n > long_len - 1)
	{
		*(dst_ptr++) = *(src_ptr++);
		n -= long_len;
	}
	if (n)
	{
		dst_ptr_char = (unsigned char*)dst_ptr;
		src_ptr_char = (unsigned char*)src_ptr;
		while (n--)
			*(dst_ptr_char++) = *(src_ptr_char++);
	}
	return (dst);
}
