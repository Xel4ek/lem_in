/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:34:48 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 19:28:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*temp_ptr;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s2) + ft_strlen(s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*s1))))
			return (NULL);
		temp_ptr = ft_strcpy_end(ptr, s1);
		ft_strcpy(temp_ptr, s2);
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin_free_first(char **s1, char const *s2)
{
	char	*ptr;
	char	*temp_ptr;
	size_t	len;

	if (s1 && s2 && *s1)
	{
		len = ft_strlen(s2) + ft_strlen(*s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*ptr))))
			return (NULL);
		temp_ptr = ft_strcpy_end(ptr, *s1);
		ft_strcpy(temp_ptr, s2);
		ft_memdel((void**)s1);
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin_free_second(char const *s1, char **s2)
{
	char	*ptr;
	char	*temp_ptr;
	size_t	len;

	if (s1 && s2 && *s2)
	{
		len = ft_strlen(*s2) + ft_strlen(s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*ptr))))
			return (NULL);
		temp_ptr = ft_strcpy_end(ptr, s1);
		ft_strcpy(temp_ptr, *s2);
		ft_memdel((void**)s2);
		return (ptr);
	}
	return (NULL);
}
