/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:31:06 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/06 16:59:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*tmp;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ptr = ft_strnew(len * sizeof(*s))))
		return (NULL);
	tmp = ptr;
	while (*s)
		*(tmp++) = (*f)(*s++);
	return (ptr);
}
