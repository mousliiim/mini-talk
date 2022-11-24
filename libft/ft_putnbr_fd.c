/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:03:45 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/12 19:24:30 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Ecrit un ou des chiffre(s) positif ou négatif donner en premier parametre 
 * sur le file descriptor donné en deuxieme paramétre.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	ft_putchar_fd(num + '0', fd);
}

/*
int	main(void)
{
	printf("\n******** FT_PUTNBR_FT ********\n");
	ft_putnbr_fd(42, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(420042, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-42, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(99999999, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putstr_fd("\n", 1);
	printf("***************************");
}
*/
