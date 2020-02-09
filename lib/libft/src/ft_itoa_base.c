/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:42 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 22:23:34 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_number_length_base(int n, int base)
{
	int len;

	len = 0;
	while (n)
	{
		n /= base;
		++len;
	}
	return (len);
}

static char	*get_numeral(char *str, int n, int len, int base)
{
	int balance;

	str[len] = 0;
	if (n)
		while (n)
		{
			balance = -(n % base);
			if (balance < 10)
				str[--len] = balance + '0';
			else
				str[--len] = balance + 'A' - 10;
			n /= base;
		}
	else
	{
		str[0] = '0';
		str[1] = 0;
	}
	return (str);
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*ptr;
	int		len;

	if (base < 2 || base > 36)
		return (NULL);
	len = get_number_length_base(nbr, base);
	if (nbr < 0 && base == 10)
		len++;
	if (!nbr)
		len++;
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	if (nbr < 0 && base == 10)
		ptr[0] = '-';
	else if (base == 10)
		nbr = -nbr;
	else if (nbr > 0)
		nbr = -nbr;
	return (get_numeral(ptr, nbr, len, base));
}
