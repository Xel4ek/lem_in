/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:56:27 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/22 16:58:56 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

size_t	ft_putstr_ptr_fd(const int fd, char const *start, char const *finish)
{
	if (start && finish && finish > start && fd > 0)
		return (write(fd, start, finish - start));
	return (0);
}
