/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:18:16 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 22:34:27 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	if (!s)
		return (NULL);
	if (!(ptr = (char*)malloc(1 + len * sizeof(*s))))
		return (NULL);
	ft_strncpy(ptr, s + start, len);
	ptr[len] = 0;
	return (ptr);
}
