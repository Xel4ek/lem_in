/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:31:44 by hwolf             #+#    #+#             */
/*   Updated: 2020/01/29 16:46:45 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int first_digit, int second_digit)
{
	if (first_digit > second_digit)
		return (second_digit);
	return (first_digit);
}
