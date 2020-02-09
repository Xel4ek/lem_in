/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:41:04 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 23:39:00 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	finish;
	size_t	len;

	if (s)
	{
		start = 0;
		while (s[start] != '\0' && \
		(s[start] == ' ' || s[start] == '\n' || s[start] == '\t'))
			start++;
		finish = ft_strlen(s) - 1;
		while (start <= finish && \
		(s[finish] == ' ' || s[finish] == '\n' || s[finish] == '\t'))
			finish--;
		if (start == finish + 1)
			return (ft_strnew(1));
		len = finish - start + 1;
		return (ft_strsub(s, start, len));
	}
	return (NULL);
}
