/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:48 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 19:14:34 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*ptr;

	len = ft_strlen(str);
	ptr = (char*)str + len;
	while (*ptr != c)
	{
		if (!len)
			return (NULL);
		--len;
		--ptr;
	}
	return (ptr);
}
