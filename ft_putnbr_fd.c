/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:04:51 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 13:05:58 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	outp(char c, int fd)
{
	(void)!write(fd, &c, 1);
}

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
		n /= 10;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = count(n);
	if (n == -2147483648)
	{
		(void)!write(fd, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		(void)!write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	outp((n % 10) + '0', fd);
	return (i);
}
