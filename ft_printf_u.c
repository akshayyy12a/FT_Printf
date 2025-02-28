/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:22:53 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 12:47:26 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_printf_u(unsigned int n)
{
	int	i;

	i = count(n);
	if (n >= 10)
	{
		ft_printf_u((n / 10));
	}
	ft_putchar_fd((n % 10) + '0', 1);
	return (i);
}
