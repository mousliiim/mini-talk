/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:56:29 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/30 01:55:31 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i;
	
	i = 8;
	while (i--)
	{
		if (octet & 1 << i)
			ft_putchar('1');
		else
			ft_putchar('0');
	}
}

int main(void)
{
	print_bits('a');
	return 0;
}
