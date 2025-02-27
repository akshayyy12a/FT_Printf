/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:36 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 13:23:13 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(int i, const char*format, ...)
{
	va_list	param;

	va_start(param, format);
	if (format[i] == '%' && format[i + 1] == 's')
		ft_printf_s(va_arg(param, char *));
	else if (format[i] == '%'
		&& (format[i + 1] == 'i' || format[i + 1] == 'd'))
		ft_printf_i(va_arg(param, int));
	else if (format[i] == '%' && format[i + 1] == 'c')
		ft_printf_c(va_arg(param, int));
	else if (format[i] == '%' && format[i + 1] == 'u')
		ft_printf_u(va_arg(param, int));
	else if (format[i] == '%' && format[i + 1] == '%')
		ft_putchar_fd('%', 1);
	else if (format[i] == '%' && format[i + 1] == 'x')
		ft_printf_x(va_arg(param, int));
	else if (format[i] == '%' && format[i + 1] == 'X')
		ft_printf_X(va_arg(param, int));
	else if (format[i] == '%' && format[i + 1] == 'p')
		ft_printf_p(va_arg(param, unsigned long));
	else if (format[i] == '\n')
		ft_putchar_fd('\n', 1);
	va_end(param);
}

int	ft_printf(const char *format, ...)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		check_format(i, format);
		i++;
	}
	return (0);
}
