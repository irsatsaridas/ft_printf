/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:03:55 by isaridas          #+#    #+#             */
/*   Updated: 2022/11/29 14:36:33 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printc(int c);
int	ft_printd(int d);
int	ft_prints(char *str);
int	ft_printu(unsigned int n);
int	ft_printx(unsigned int n, const char format);
int	ft_printp(unsigned long long n);

#endif
