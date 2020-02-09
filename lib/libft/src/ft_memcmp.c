/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:28:55 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 17:12:02 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	long			*ptr1_ptr;
	long			*ptr2_ptr;
	unsigned char	*ptr1_ptr_char;
	unsigned char	*ptr2_ptr_char;
	size_t			long_len;

	ptr1_ptr = (long*)ptr1;
	ptr2_ptr = (long*)ptr2;
	long_len = sizeof(*ptr1_ptr);
	if ((ptr1 == ptr2) || !n)
		return (0);
	while (n > long_len - 1)
	{
		if (*(ptr1_ptr++) != *(ptr2_ptr++))
			return (1);
		n -= long_len;
	}
	if (!n)
		return (0);
	ptr1_ptr_char = (unsigned char*)ptr1_ptr;
	ptr2_ptr_char = (unsigned char*)ptr2_ptr;
	while (n--)
		if (*(ptr1_ptr_char++) != *(ptr2_ptr_char++))
			return (1);
	return (0);
}
