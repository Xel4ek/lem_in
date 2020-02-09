/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:00:36 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/29 16:55:47 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftprintf_core(const int fd, char *ptr, t_param *param)
{
	int		printed;
	char	*ptr_last;

	printed = 0;
	while (*ptr)
	{
		ptr_last = ft_strch(ptr, '%');
		printed += ft_putstr_ptr_fd(fd, ptr, ptr_last);
		ptr = ptr_last;
		if (*ptr)
			if (get_param(param, &ptr))
			{
				get_item(param);
				apply_flags(param);
				printed += ft_putstring(fd, param->str, param->line_size);
				ft_memdel((void **)&param->str);
			}
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	t_param	param;

	va_start(param.ap, format);
	printed = ftprintf_core(1, (char*)format, &param);
	va_end(param.ap);
	return (printed);
}

int	ft_printf_fd(const int fd, const char *format, ...)
{
	int		printed;
	t_param	param;

	va_start(param.ap, format);
	printed = ftprintf_core(fd, (char*)format, &param);
	va_end(param.ap);
	return (printed);
}
