/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:55:07 by lduchemi          #+#    #+#             */
/*   Updated: 2023/10/26 16:24:18 by lduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += write(1, va_arg(args, char), 1);
	else if (format == 'd' || format == 'i')
		ft_put_digit(va_arg(args, int), 10, &length);
	else if (format == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		ft_put_digit(va_arg(args, int), 16, &length);

}

void	my_printf(const char *format, ...)
{
	va_list	args;
	int		num;
	char	*str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'd')
			{
				num = va_arg(args, int);
			}
			else if (*(format + 1) == 's')
			{
				str = va_arg(args, char *);
				printf("%s ", str);
			}
			format += 2;
		}
		else
		{
			putchar(*format++);
		}
	}
	va_end(args);
}

int	main(void)
{
	my_printf("The answer is %d and it's %s.\n", 42, "correct");
	return (0);
}
