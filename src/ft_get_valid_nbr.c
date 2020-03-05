/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_valid_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:45:18 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:45:20 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_atoi_ll(const char *str)
{
	int						i;
	int						ng;
	long long int			nb;

	i = 0;
	ng = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
		ng = 44 - (int)str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nb * 10) / 10 != nb)
		{
			nb = ng == 1 ? -1 : 0;
			break ;
		}
		nb = nb * 10 + ((int)str[i] - 48);
		i++;
	}
	return (nb * ng);
}

int						ft_get_valid_nbr(const char *str)
{
	int 			i;
	long long int	nbr;

	i = -1;

	if (!str)
		return (-1);
	if (!str[0])
		return (-1);
	if (str[0] == '+')
		i++;
	while (str[i + 1] == '0')
		i++;
	if (ft_strlen(&str[i + 1]) > 11)
		return (-1);
	while (str[++i] != '\0')
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	nbr = ft_atoi_ll(str);
	if (nbr < 0 || nbr != (long long int)((int)nbr))
		return (-1);
	return ((int)nbr);
}
