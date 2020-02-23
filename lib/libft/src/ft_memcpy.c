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

void	*ft_memcpy(void *const dst, const void *src, size_t n)
{
	unsigned long int			*dst_ptr;
	unsigned long int			*src_ptr;
	unsigned char	*dst_ptr_char;
	unsigned char	*src_ptr_char;
	size_t			long_len;

	long_len = sizeof(unsigned long int);
	if ((dst == src) || !n)
		return (dst);
	dst_ptr_char = (unsigned char*)dst;
	while (((unsigned long int) dst_ptr_char & (sizeof(unsigned long int) - 1)) && n--)
		*dst_ptr_char++ = *(unsigned char*)src++;
	dst_ptr = (unsigned long int*)dst_ptr_char;
	src_ptr = (unsigned long int*)src;
	while (n > long_len - 1)
	{
		*dst_ptr++ = *src_ptr++;
		n -= long_len;
	}
	if (n)
	{
		dst_ptr_char = (unsigned char*)dst_ptr;
		src_ptr_char = (unsigned char*)src_ptr;
		while (n--)
			*dst_ptr_char++ = *src_ptr_char++;
	}
	return (dst);
}
