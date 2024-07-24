/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:01:04 by jheo              #+#    #+#             */
/*   Updated: 2024/03/28 17:14:29 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	char	c;

	len = 0;
	if (n == -2147483648)
		return (max_minus());
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_puthex(unsigned int n, const char *format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, format);
	}
	if (*format == 'x')
	{
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else if (*format == 'X')
	{
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	return (len);
}

int	ft_putpoint(unsigned long long n, const char *format)
{
	int	len;

	len = 0;
	if (n > 16)
	{
		len += ft_putpoint(n / 16, format);
	}
	len += write(1, &"0123456789abcdef"[n % 16], 1);
	return (len);
}

int	ft_is_pointer(void *num, const char *format)
{
	int					len;
	unsigned long long	n;

	n = (unsigned long long)num;
	len = 0;
	if (*format == 'p' && n == 0)
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	write(1, "0x", 2);
	len += 2;
	len += ft_putpoint(n, format);
	return (len);
}

int	ft_u_putnbr(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
	{
		len += ft_u_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}
