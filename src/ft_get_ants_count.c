/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ants_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:42:28 by ayooden           #+#    #+#             */
/*   Updated: 2020/02/18 18:53:22 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
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
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
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

int						ft_get_ants_count(int fd)
{
	long long int	nbr;
	char			*buf;
	int				i;

	i = -1;
	if (!get_next_line(fd, &buf))
		return (-1);
	if (buf[0] == '+')
		i++;
	while (buf[i + 1] == '0')
		i++;
	if (ft_strlen(&buf[i + 1]) > 11)
		return (-1);
	while (buf[++i] != '\0')
		if (buf[i] < '0' || buf[i] > '9')
		{
			ft_memdel((void **)&buf);
			return (-1);
		}
	nbr = ft_atoi_ll(buf);
	ft_memdel((void **)&buf);
	if (nbr <= 0 )//|| nbr != (long long int)((int)nbr))
		return (-1);
	return (nbr);
}
