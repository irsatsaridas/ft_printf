/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:47:28 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 20:44:27 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_printd(int d)
{
	int	minus;

	minus = 0;
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (d < 0 && d != -2147483648)
	{
		write(1, "-", 1);
		d = -d;
		minus = 1;
	}
	if (d >= 10)
	{
		ft_printd(d / 10);
		ft_printd(d % 10);
	}
	else
		ft_printc(d + '0');
	return (ft_intlen(d) + minus);
}
