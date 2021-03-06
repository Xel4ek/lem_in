/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:41:29 by ayooden           #+#    #+#             */
/*   Updated: 2020/03/03 18:41:24 by ayooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_in_str(char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
