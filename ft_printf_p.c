/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:18 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 14:23:57 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static int	ft_putnbr_base(unsigned long nbr)
{
	char	*base;
	int		i;

	i = count(nbr);
	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16);
	ft_putchar_fd(base[(nbr % 16)], 1);
	return (i);
}

int	ft_printf_p(unsigned long nb)
{
	int	i;

	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	i = ft_putnbr_base(nb);
	return (i + 2);
}
