/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:28:43 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 19:29:34 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unbrlen(uintmax_t nbr, int base)
{
	int len;

	len = 1;
	while (nbr /= base)
		len++;
	return (len);
}

int	ft_nbrlen(intmax_t nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
