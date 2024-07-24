/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:11:17 by jheo              #+#    #+#             */
/*   Updated: 2024/03/28 16:54:07 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	max_minus(void);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, const char *format);
int	ft_is_pointer(void *num, const char *format);
int	ft_putpoint(unsigned long long n, const char *format);
int	ft_u_putnbr(unsigned int n);
int	find_type(va_list ap, const char *format);
int	print_format(va_list ap, const char *format);
int	ft_printf(const char *format, ...);
#endif
