/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:00:57 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/06 18:03:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void		ft_putnbr_fd(int n, int fd)
{
	char	ptr[20];
	int		len;

	len = get_number_length(n);
	if (n < 0)
	{
		ptr[0] = '-';
		len++;
	}
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
	ft_putstr_fd(ptr, fd);
}
