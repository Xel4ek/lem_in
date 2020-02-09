/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:06:52 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:00:11 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(src);
	if (!(ptr = (char*)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	ptr[len] = 0;
	while (len--)
		ptr[len] = src[len];
	return (ptr);
}
