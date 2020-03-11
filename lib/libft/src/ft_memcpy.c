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
	size_t			*dst_ptr;
	size_t			*src_ptr;
	unsigned char	*dst_ptr_char;
	unsigned char	*src_ptr_char;

	if (!(n++) || dst == src)
		return (dst);
	dst_ptr_char = (unsigned char*)dst;
	while (--n && ((size_t)dst_ptr_char & 7u))
		*dst_ptr_char++ = *(unsigned char*)src++;
	dst_ptr = (size_t*)dst_ptr_char;
	src_ptr = (size_t*)src;
	while (n > 7u)
	{
		*dst_ptr++ = *src_ptr++;
		n -= 8u;
	}
	if (!n)
		return (dst);
	dst_ptr_char = (unsigned char*)dst_ptr;
	src_ptr_char = (unsigned char*)src_ptr;
	while (n--)
		*dst_ptr_char++ = *src_ptr_char++;
	return (dst);
}
