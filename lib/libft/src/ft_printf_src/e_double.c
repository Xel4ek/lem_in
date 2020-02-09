/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_double.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:04:20 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 19:02:27 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		calculate_number_e(char *str, int max_len, intmax_t exponent)
{
	int i;
	int count;

	count = 0;
	i = (int)(exponent) - (int)(1u << 14u) - 62;
	if (i < 0)
	{
		while (i++)
		{
			count += shift_string(str, max_len + 1);
			division_two_e(str, max_len);
		}
	}
	else
		while (i--)
		{
			count += shift_string(str, max_len + 1);
			multiply_two(str, max_len);
		}
	return (count);
}

int		round_e_nbr(t_param *param, char *string, int max_len, int shift)
{
	int j;

	j = max_len;
	shift += shift_string(string, max_len);
	while (j--)
	{
		if (j == param->precision + 4)
			if (string[j] > 4)
				string[j - 1]++;
		if (string[j] > 9)
		{
			string[j - 1]++;
			string[j] %= 10;
		}
	}
	return (-shift - shift_string(string, max_len) + param->precision + 16);
}

void	write_rezult_e(t_param *param, char *str, int max_len, int shift)
{
	int		i;
	int		delta;
	int		k;
	char	ptr[max_len - BASE_NBR_LEN + 16];
	char	*temp;

	i = 3;
	delta = 1;
	k = 0;
	shift = round_e_nbr(param, str, max_len, shift);
	while (i < param->precision + 4)
	{
		if (delta-- == 0)
			ptr[k++] = '.';
		ptr[k++] = (char)(str[i++] + '0');
	}
	ptr[k] = 0;
	temp = ft_strjoin(param->str, ptr);
	ft_memdel((void **)&param->str);
	param->str = temp;
	param->line_size = ft_strlen(param->str);
	add_exponent(param, shift);
}

void	ft_dtoa_e_helper(t_param *param, int max_len, uintmax_t mantissa,
							intmax_t exponent)
{
	int			i;
	char		str[max_len + 1];
	int			shift;
	intmax_t	zero;

	i = max_len + 1;
	zero = mantissa;
	while (i--)
	{
		str[i] = (char)(mantissa % 10);
		mantissa /= 10;
	}
	if (zero)
	{
		shift = calculate_number_e(str, max_len, exponent);
		write_rezult_e(param, str, max_len, shift - 6);
	}
	else
	{
		write_rezult_e(param, str, max_len, param->precision + 16);
	}
}

int		ft_dtoa_e(long double nbr, t_param *param)
{
	int			max_len;
	uintmax_t	mantissa;
	intmax_t	exponent;

	if (param->precision < 0)
		param->precision = DEFAULT_PRECISION;
	ft_memcpy(&mantissa, &nbr, sizeof(mantissa));
	ft_memcpy(&exponent, (void *)(&nbr) + sizeof(mantissa), sizeof(exponent));
	param->sign = (char)(((uintmax_t)exponent & 0x8000u) >> 15u);
	exponent = (uintmax_t)exponent & 0x7fffu;
	max_len = param->precision + BASE_NBR_LEN;
	ft_dtoa_e_helper(param, max_len, mantissa, exponent);
	return (1);
}
