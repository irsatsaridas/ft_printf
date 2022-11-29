/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:14:14 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/29 14:50:32 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned long long n)
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

static void	ft_putx(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putx(n / 16);
		ft_putx(n % 16);
	}
	else
	{
		if (n < 10)
			ft_printc(n + '0');
		else
			ft_printc(n - 10 + 'a');
	}
}

int	ft_printp(unsigned long long n)
{
	write(1, "0x", 2);
	if (n == 0)
		return (write(1, "0", 1) + 2);
	else
		ft_putx(n);
	return (ft_hexlen(n) + 2);
}
