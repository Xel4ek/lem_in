/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:58:17 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 19:28:29 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char tmp;

	tmp = (unsigned char)c;
	ptr = (unsigned char*)src;
	while (n--)
		if (*(ptr++) == tmp)
			return (ptr - 1);
	return (NULL);
}
