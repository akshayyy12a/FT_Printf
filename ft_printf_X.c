/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:41:01 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 13:20:02 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(int nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(-(nbr / 16));
		ft_putchar_fd(base[-(nbr % 16)], 1);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = nbr * -1;
	}
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16);
	ft_putchar_fd(base[(nbr % 16)], 1);
}

void	ft_printf_bx(int nb)
{
	ft_putnbr_base(nb);
}
