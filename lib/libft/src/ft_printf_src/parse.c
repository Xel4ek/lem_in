/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:13:37 by hwolf             #+#    #+#             */
/*   Updated: 2019/10/19 18:13:37 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->hash = 0;
}

void	init_param(t_param *param)
{
	param->str = NULL;
	param->line_size = 0;
	param->precision = -1;
	param->type = 0;
	param->length = 0;
	param->sign = 0;
	init_flag(&(param->flag));
	param->width = 0;
}

int		get_param(t_param *new_param, char **str)
{
	(*str)++;
	init_param(new_param);
	while (get_flag((*str), &(new_param->flag)))
		(*str)++;
	get_width(str, new_param);
	get_precision(str, new_param);
	if ((new_param->length = get_length(*str)))
	{
		if (new_param->length > 'z')
			(*str)++;
		(*str)++;
	}
	while (**str && !(new_param->type = get_type(*str)))
		(*str)++;
	if (!(new_param->type))
		return (0);
	if (!(new_param->str = (char *)malloc(2)))
		return (0);
	*(new_param->str) = 0;
	(*str)++;
	return (1);
}
