/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:14:14 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 20:19:28 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_putx(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_putx(n / 16, format);
		ft_putx(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_printc(n + '0');
		else
		{
			if (format == 'x' || format == 'p')
				ft_printc(n - 10 + 'a');
			else if (format == 'X')
				ft_printc(n - 10 + 'A');
		}
	}
}

int	ft_printx(unsigned int n, const char format)
{
	write(1, "0x", 2);
	if (!n)
		return (write(1, "0", 1));
	else
		ft_putx(n, format);
	return (ft_hexlen(n) + 2);
}
