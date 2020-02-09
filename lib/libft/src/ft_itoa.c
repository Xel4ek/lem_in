/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:51:46 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 20:06:13 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_number_length(int n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = get_number_length(n);
	if (n <= 0)
		len++;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	else
		n = -n;
	ptr[len] = 0;
	if (n)
		while (n)
		{
			ptr[--len] = -(n % 10) + '0';
			n /= 10;
		}
	else
	{
		ptr[0] = '0';
		ptr[1] = 0;
	}
	return (ptr);
}
