/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:54:31 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 17:59:41 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_number(char *str, int max_len, intmax_t exponent)
{
	int i;

	i = (int)(exponent) - (int)(1 << 14) - 62;
	if (i < 0)
		while (i++)
			division_two(str, max_len, i);
	else
		while (i--)
			multiply_two(str, max_len);
}

void	write_rezult(t_param *param, const char *str,
		const int max_len, int delta)
{
	int		i;
	int		k;
	char	*temp;
	char	ptr[max_len - BASE_NBR_LEN + 16];

	k = 0;
	i = BASE_NBR_LEN - 1;
	if (delta > 1 && str[i] == 0)
	{
		i++;
		delta--;
	}
	if (delta < 1)
		delta = 1;
	while (i < max_len - 1)
	{
		if (delta-- == 0)
			ptr[k++] = '.';
		ptr[k++] = str[i++] + '0';
	}
	ptr[k] = 0;
	temp = ft_strjoin(param->str, ptr);
	ft_memdel((void **)&param->str);
	param->str = temp;
	param->line_size = ft_strlen(param->str);
}

void	ft_dtoa_helper(t_param *param, int max_len, uintmax_t mantissa,
					intmax_t exponent)
{
	int		i;
	int		power;
	char	str[max_len + 1];

	i = (int)(exponent) - (int)(1 << 14) - 62;
	power = BASE_NBR_LEN + ft_ceil(((double)i) * LOG2) - 6;
	i = 0;
	while (i < max_len)
		str[i++] = 0;
	i = BASE_NBR_LEN + (power > 0 ? power : 0);
	while (i--)
	{
		str[i] = mantissa % 10;
		mantissa /= 10;
	}
	calculate_number(str, max_len, exponent);
	write_rezult(param, str, max_len, power + 1);
}

int		ft_dtoa(long double nbr, t_param *param)
{
	int			max_len;
	uintmax_t	mantissa;
	intmax_t	exponent;
	int			power;
	int			i;

	if (param->precision < 0)
		param->precision = DEFAULT_PRECISION;
	ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
	ft_memcpy(&exponent, (void *)(&nbr) + sizeof(mantissa), sizeof(exponent));
	param->sign = (exponent & 0x8000) >> 15;
	exponent &= 0x7fff;
	i = (int)(exponent) - (int)(1 << 14) - 62;
	power = BASE_NBR_LEN + ft_ceil(((double)i) * LOG2) - 6;
	max_len = param->precision + (power > 0 ? power : 0) + BASE_NBR_LEN + 1;
	ft_dtoa_helper(param, max_len, mantissa, exponent);
	return (1);
}

void	division_two(char *str, int max_len, int i)
{
	int j;

	j = max_len;
	while (j--)
	{
		str[j + 1] += (str[j] % 2) * 5;
		str[j] /= 2;
		if (str[j + 1] > 9)
		{
			str[j + 1] %= 10;
			str[j] += 1;
		}
		if (i == 0 && j == max_len - 2)
			if (str[j + 1] > 5)
				str[j]++;
	}
}
