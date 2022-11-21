/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:52:39 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 19:46:02 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}*/

int	ft_printu(unsigned int n)
{
	static int		numofp;

	numofp = 0;
	if (n == 0)
		numofp += write(1, "0", 1);
	if (n >= 10)
	{
		ft_printu(n / 10);
		ft_printu(n % 10);
	}
	else
		numofp += ft_printc(n + '0');
	return (numofp);
}
