/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:18:41 by jheo              #+#    #+#             */
/*   Updated: 2024/03/28 17:13:22 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_type(va_list ap, const char *format)
{
	int	len;

	len = -1;
	if (*format == 'c')
		len = ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		len = ft_putnbr(va_arg(ap, int));
	else if (*format == 'x' || *format == 'X')
		len = ft_puthex(va_arg(ap, unsigned int), format);
	else if (*format == 'p')
		len = ft_is_pointer(va_arg(ap, void *), format);
	else if (*format == 'u')
		len = ft_u_putnbr(va_arg(ap, unsigned int));
	else if (*format == '%')
		len = ft_putchar('%');
	return (len);
}

int	print_format(va_list ap, const char *format)
{
	int	result;
	int	type;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			type = find_type(ap, format);
			if (type == -1)
				return (-1);
			result += type;
		}
		else
		{
			write(1, format, 1);
			result++;
		}
		format++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = print_format(ap, format);
	va_end(ap);
	return (result);
}
