/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:30:40 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 19:31:17 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_ceil(long double nbr)
{
	int inbr;

	if (nbr - (inbr = (int)nbr) > .0)
		return (inbr + 1);
	return (inbr);
}

long long int	ft_ceil_ll(long double nbr)
{
	long long int inbr;

	if (nbr - (inbr = (long long int)nbr) > .0)
		return (inbr + 1);
	return (inbr);
}
