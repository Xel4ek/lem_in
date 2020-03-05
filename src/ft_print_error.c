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

#include <unistd.h>
#include "libft.h"

static int ft_print_error_2(long int error_code)
{
	int fd;

	fd = STDERR_FILENO;
	if (error_code == -7)
		ft_printf_fd(fd,"Start or end is duplicated\n");
	else if (error_code == -8)
		ft_printf_fd(fd,"Wrong start or end declaration\n");
	else if (error_code == -9)
		ft_printf_fd(fd,"No tubes\n");
	else if (error_code == -10)
		ft_printf_fd(fd,"No start or end\n");
	else if (error_code == -11)
		ft_printf_fd(fd,"Wrong line in edge declarations\n");
	else if (error_code == -12)
		ft_printf_fd(fd,"Undeclared room in edge\n");
	else if (error_code == -13)
		ft_printf_fd(fd,"No path\n");
	else if (error_code == -14)
		ft_printf_fd(fd,"Empty map\n");
	else if (error_code == -15)
		ft_printf_fd(fd,"No rooms\n");
	return (0);
}

int ft_print_error(long int error_code)
{
	int fd;

	fd = STDERR_FILENO;
	ft_printf_fd(fd,"ERROR: ");
	if (error_code < -7)
		return (ft_print_error_2(error_code));
	if (error_code == -1)
		ft_printf_fd(fd,"Invalid number of ants\n");
	else if (error_code == -2)
		ft_printf_fd(fd,"Wrong line in room declarations\n");
	else if (error_code == -3)
		ft_printf_fd(fd,"Wrong file\n");
	else if (error_code == -4)
		ft_printf_fd(fd,"Wrong coordinates\n");
	else if (error_code == -5)
		ft_printf_fd(fd,"Room's coordinates are duplicated\n");
	else if (error_code == -6)
		ft_printf_fd(fd,"Room's name is duplicated\n");
	else if (error_code == -7)
		ft_printf_fd(fd,"Start or end is duplicated\n");
	return (0);
}
