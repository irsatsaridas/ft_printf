/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:16:46 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 20:23:20 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printc(va_arg(args, int));
	else if (format == 's')
		print_length += ft_prints(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_printx(va_arg(args, unsigned int), format);
	else if (format == 'd' || format == 'i')
		print_length += ft_printd(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_printu(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_printx(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += write(1, "%%", 1);
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		numofp;
	va_list	args;

	va_start(args, format);
	i = -1;
	numofp = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			numofp += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			numofp += write(1, &format[i], 1);
	}
	va_end(args);
	return (numofp);
}
