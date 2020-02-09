/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:29:47 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/08 12:37:42 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	ans;
	long long int	test;

	ans = 0;
	sign = 0;
	while ((*str == ' ') || (*str > 8 && *str <= 14))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = 1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		test = ans;
		ans = ans * 10 + *str - '0';
		if (test > (ans / 10))
			return (sign ? 0 : -1);
		++str;
	}
	if (sign)
		return (-ans);
	return (ans);
}
