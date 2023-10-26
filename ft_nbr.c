/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:20:00 by lduchemi          #+#    #+#             */
/*   Updated: 2023/10/26 18:21:16 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(long long int number, int base, int *length, char x)
{
	char	*hexadecimal;

	if (x == 'X')
		hexadecimal = "0123456789ABCDEF";
	else
		hexadecimal = "0123456789abcdef";
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		ft_put_hex((number / base), base, length, x);
	*length += write(1, &hexadecimal[number % base], 1);
}

void	ft_put_di(int number, int *length)
{
	char	*decimal;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	decimal = "0123456789";
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= 10)
		ft_put_di((number / 10), length);
	*length += write(1, &decimal[number % 10], 1);
}
