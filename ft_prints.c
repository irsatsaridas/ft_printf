/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:20:42 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/21 20:59:58 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}
