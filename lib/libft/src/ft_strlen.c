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

size_t	ft_strlen(const char *str)
{
	const char				*char_ptr;
	const unsigned long int	*longword_ptr;
	unsigned long int		longword;
	unsigned long int		himagic;
	unsigned long int		lomagic;

	char_ptr = str;
	while ((unsigned long int) char_ptr & (sizeof(longword) - 1))
		if (*char_ptr++ == '\0')
			return (char_ptr - str - 1);
	longword_ptr = (unsigned long int*)char_ptr;
	himagic = 0x8080808080808080L;
	lomagic = 0x0101010101010101L;
	longword = *longword_ptr++;
	while (((longword - lomagic) & ~longword & himagic) == 0)
		longword = *longword_ptr++;
	char_ptr = (const char *) (longword_ptr - 1) - 1;
	while (*(++char_ptr))
		;
	return (char_ptr - str);
}