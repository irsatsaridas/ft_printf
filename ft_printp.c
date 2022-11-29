/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:14:14 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 22:29:25 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(uintptr_t n)
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

static void	ft_putx(uintptr_t n)
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

int	ft_printp(unsigned int n)
{
	write(1, "0x", 2);
	if (!n)
		return (write(1, "0", 1));
	else
		ft_putx(n);
	return (ft_hexlen(n) + 2);
}
