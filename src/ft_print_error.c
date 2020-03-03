/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:48:25 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:48:27 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_print_error_2(int error_code)
{
	if (error_code == -7)
		ft_printf_fd(2,"Start or end is duplicated\n");
	else if (error_code == -8)
		ft_printf_fd(2,"Wrong start or end declaration\n");
	else if (error_code == -9)
		ft_printf_fd(2,"No tubes\n");
	else if (error_code == -10)
		ft_printf_fd(2,"No start or end\n");
	else if (error_code == -11)
		ft_printf_fd(2,"Wrong line in edge declarations\n");
	else if (error_code == -12)
		ft_printf_fd(2,"Undeclared room in edge\n");
	else if (error_code == -13)
		ft_printf_fd(2,"No path\n");
	else if (error_code == -14)
		ft_printf_fd(2,"Empty map\n");
	else if (error_code == -15)
		ft_printf_fd(2,"No rooms\n");
	return (0);
}

int ft_print_error(int error_code)
{
	ft_printf_fd(2,"ERROR: ");
	if (error_code < -7)
		return (ft_print_error_2(error_code));
	if (error_code == -1)
		ft_printf_fd(2,"Invalid number of ants\n");
	else if (error_code == -2)
		ft_printf_fd(2,"Wrong line in room declarations\n");
	else if (error_code == -3)
		ft_printf_fd(2,"Wrong file\n");
	else if (error_code == -4)
		ft_printf_fd(2,"Wrong coordinates\n");
	else if (error_code == -5)
		ft_printf_fd(2,"Room's coordinates are duplicated\n");
	else if (error_code == -6)
		ft_printf_fd(2,"Room's name is duplicated\n");
	else if (error_code == -7)
		ft_printf_fd(2,"Start or end is duplicated\n");
	return (0);
}
