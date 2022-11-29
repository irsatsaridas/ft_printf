/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:52:39 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 20:51:09 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
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

int	ft_printu(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n >= 10)
	{
		ft_printu(n / 10);
		ft_printu(n % 10);
	}
	else
		ft_printc(n + '0');
	return (ft_intlen(n));
}
