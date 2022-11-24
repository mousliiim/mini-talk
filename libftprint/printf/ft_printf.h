/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:09:50 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/19 02:14:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789abcdef0123456789ABCDEF"

typedef unsigned long	t_uintptr;

int		ft_printf(const char *format, ...);
int		ft_putstr(const char *str);
int		ft_putnbr(t_uintptr nb, unsigned int base, int upper);
int		ft_putchar(int c);
int		ft_parse_arg(const char c, va_list *list);
int		exec_d_or_i(va_list *args);

#endif
