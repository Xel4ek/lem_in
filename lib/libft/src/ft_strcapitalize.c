/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:53:55 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 23:04:18 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_up_char(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

static char	ft_low_char(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

static int	ft_is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char		*ft_strcapitalize(char *str)
{
	char *tmp;

	tmp = str;
	while (*str)
	{
		if (ft_is_letter(*str))
		{
			*str = ft_up_char(*str);
			++str;
			while (ft_is_letter(*str))
			{
				*str = ft_low_char(*str);
				++str;
			}
		}
		++str;
	}
	return (tmp);
}
