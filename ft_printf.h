/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:04:49 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/28 13:04:39 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_s(char *s);
int	ft_printf_i(int n);
int	ft_printf_c(char c);
int	ft_printf_u(unsigned int n);
int	ft_printf_x(int nb);
int	ft_printf_bx(int nb);
int	ft_printf_p(unsigned long nb);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);

#endif
