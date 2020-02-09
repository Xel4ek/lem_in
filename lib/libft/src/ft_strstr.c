/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:03 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 17:48:20 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t i;
	size_t j;

	i = 0;
	if (!(*str2))
		return ((char*)str1);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j])
		{
			++j;
			if (!str2[j])
				return ((char*)str1 + i);
		}
		++i;
	}
	return (NULL);
}
