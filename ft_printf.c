/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:36 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 17:18:12 by shessoun         ###   ########.fr       */
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

static void	check_format(char c, va_list args)
{
	if (c == 's')
		ft_printf_s(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_printf_i(va_arg(args, int));
	else if (c == 'c')
		ft_printf_c(va_arg(args, int));
	else if (c == 'u')
		ft_printf_u(va_arg(args, int));
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'x')
		ft_printf_x(va_arg(args, int));
	else if (c == 'X')
		ft_printf_bx(va_arg(args, int));
	else if (c == 'p')
		ft_printf_p(va_arg(args, unsigned long));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	param;

	i = 0;
	va_start(param, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_format(format[i + 1]) == 1)
		{
			check_format(format[i + 1], param);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (0);
}
