/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:03:30 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:34:16 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline long long int	ft_result(const char *char_ptr, const char *str)
{
	if (char_ptr[0] == 0)
		return (char_ptr - str);
	if (char_ptr[1] == 0)
		return (char_ptr - str + 1);
	if (char_ptr[2] == 0)
		return (char_ptr - str + 2);
	if (char_ptr[3] == 0)
		return (char_ptr - str + 3);
	if (char_ptr[4] == 0)
		return (char_ptr - str + 4);
	if (char_ptr[5] == 0)
		return (char_ptr - str + 5);
	if (char_ptr[6] == 0)
		return (char_ptr - str + 6);
	if (char_ptr[7] == 0)
		return (char_ptr - str + 7);
	return (-1);
}

size_t						ft_strlen(const char *str)
{
	const char						*char_ptr;
	const unsigned long long int	*longword_ptr;
	unsigned long long int			longword;
	long long int					temp;

	char_ptr = str;
	while (((unsigned long long int)char_ptr) & (sizeof(longword) - 1))
		if (*char_ptr++ == 0)
			return (char_ptr - str - 1);
	longword_ptr = (unsigned long long int *)char_ptr;
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - LOMAGIC) & ~longword & HIMAGIC) != 0)
		{
			char_ptr = (const char *)(longword_ptr - 1);
			temp = ft_result(char_ptr, str);
			if (temp != -1)
				return (temp);
		}
	}
}
