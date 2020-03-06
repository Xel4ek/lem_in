/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:22:55 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:10:03 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned long	*dst_ptr;
	unsigned long	cccc;
	unsigned char	*dst_ptr_char;
	size_t			long_len;

	dst_ptr = (unsigned long*)dst;
	cccc = (unsigned char)c;
	cccc |= cccc << 8u;
	cccc |= cccc << 16u;
	cccc |= (cccc << 16u) << 16u;
	long_len = sizeof(*dst_ptr);
	while (n > long_len - 1)
	{
		*(dst_ptr++) = cccc;
		n -= long_len;
	}
	if (n)
	{
		dst_ptr_char = (unsigned char*)dst_ptr;
		while (n--)
			*(dst_ptr_char++) = c;
	}
	return (dst);
}
