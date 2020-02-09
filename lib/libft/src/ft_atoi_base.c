/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:32:08 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/18 23:49:27 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	add_number(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else
		return ((c - 'A' + 10));
}

static int	check_base(char c, int base)
{
	if (!((c >= '0' && c <= '9') || \
		(c >= 'a' && c <= 'z') || \
		(c >= 'A' && c <= 'Z')))
		return (0);
	if ((c >= '0' && c <= '9') && ((c - '0') > base))
		return (0);
	if ((c >= 'a' && c <= 'z') && ((c - 'a' + 10) > base))
		return (0);
	if ((c >= 'A' && c <= 'Z') && ((c - 'A' + 10) > base))
		return (0);
	return (1);
}

int			ft_atoi_base(const char *str, int base)
{
	int				sign;
	int				ans;
	unsigned char	*ptr;

	ptr = (unsigned char*)str;
	ans = 0;
	sign = 0;
	while (*ptr <= ' ')
		++ptr;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = 1;
		++ptr;
	}
	while (check_base(*ptr, base))
	{
		ans = ans * base + add_number(*ptr);
		++ptr;
	}
	if (sign)
		return (-ans);
	return (ans);
}
