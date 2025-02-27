/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:55:18 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 13:17:44 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16);
	ft_putchar_fd(base[(nbr % 16)], 1);
}

void	ft_printf_p(unsigned long nb)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_putnbr_base(nb);
}
