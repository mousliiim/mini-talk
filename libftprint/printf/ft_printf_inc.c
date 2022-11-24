/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_inc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:19:52 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/19 02:07:38 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnbr(t_uintptr nb, unsigned int base, int upper)
{
	static int	count;

	count = 0;
	if (nb >= base)
		ft_putnbr((nb / base), base, upper);
	count += ft_putchar(HEX_BASE[nb % base + upper * 16]);
	return (count);
}
