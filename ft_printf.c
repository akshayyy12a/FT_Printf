/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:36 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 13:04:01 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		return (1);
	}
	return (0);
}

static int	check_format(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 's')
		i += ft_printf_s(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		i += ft_printf_i(va_arg(args, int));
	else if (c == 'c')
		i += ft_printf_c(va_arg(args, int));
	else if (c == 'u')
		i += ft_printf_u(va_arg(args, int));
	else if (c == '%')
		i += ft_putchar_fd('%', 1);
	else if (c == 'x')
		i += ft_printf_x(va_arg(args, int));
	else if (c == 'X')
		i += ft_printf_bx(va_arg(args, int));
	else if (c == 'p')
		i += ft_printf_p(va_arg(args, unsigned long));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	param;

	i = 0;
	len = 0;
	va_start(param, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_format(format[i + 1]) == 1)
		{
			len += check_format(format[i + 1], param);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	return (len);
}
