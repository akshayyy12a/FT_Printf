/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shessoun <shessoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:04:49 by shessoun          #+#    #+#             */
/*   Updated: 2025/02/27 00:31:06 by shessoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft.h"

int		ft_printf(const char *format, ...);
void	ft_printf_s(char *s);
void	ft_printf_i(int n);
void	ft_printf_c(char c);
void	ft_printf_u(int n);

#endif
