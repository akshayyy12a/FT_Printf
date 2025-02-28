/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:41:01 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 13:16:59 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static int	ft_putnbr_base(unsigned int nbr)
{
	char	*base;
	int		i;

	i = count(nbr);
	if (nbr > 2147483647)
		i = 8;
	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16);
	ft_putchar_fd(base[(nbr % 16)], 1);
	return (i);
}

int	ft_printf_bx(int nb)
{
	int	i;

	i = ft_putnbr_base(nb);
	return (i);
}
