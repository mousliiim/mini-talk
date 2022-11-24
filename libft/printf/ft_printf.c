/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:06:25 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/19 02:35:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_d_or_i(va_list *args)
{
	long int				nbr;

	nbr = va_arg(*args, int);
	if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr(nbr * -1, 10, 0));
	return (ft_putnbr(nbr, 10, 0));
}

int	ft_parse_arg(const char c, va_list *args)
{
	t_uintptr	preturn;

	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (exec_d_or_i(args));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int), 10, 0));
	else if (c == 'p')
	{
		preturn = (t_uintptr)va_arg(*args, void *);
		if (!preturn)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") \
			+ ft_putnbr(preturn, 16, 0));
	}
	else if (c == 'x' || c == 'X')
		return (ft_putnbr(va_arg(*args, unsigned int), 16, c == 'X'));
	return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			count += ft_parse_arg(format[++i], &args);
		else
			count += ft_putchar(format[i]);
	}
	va_end(args);
	return (count);
}
