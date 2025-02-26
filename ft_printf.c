/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:03:36 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 00:36:36 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	param;
	char	c;

	va_start(param, format);
	c = *format;
	while (c != '\0')
	{
		c = *format;
		format++;
		if (c == 's')
			ft_printf_s(va_arg(param, char *));
		else if (c == 'i' || c == 'd')
			ft_printf_i(va_arg(param, int));
		else if (c == 'c')
			ft_printf_c(va_arg(param, int));
		else if (c == 'u')
			ft_printf_u(va_arg(param, int));
	}
	return (0);
}
