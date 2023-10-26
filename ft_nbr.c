/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:20:00 by lduchemi          #+#    #+#             */
/*   Updated: 2023/10/26 16:19:19 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


void	ft_put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	//if (!number)
	//	*length += write(1, "(null)", 1);
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		ft_put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}
