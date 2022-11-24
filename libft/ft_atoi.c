/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:25:23 by mmourdal          #+#    #+#             */
/*   Updated: 2022/10/20 04:17:50 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Transforme une chaine de caractere donnée en Parametre
 * en entier
*/

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	printf("\n************** FT_ATOI *************\n");
	printf("\n'42' : %d\n", ft_atoi("42"));
	printf("'-42' : %d\n", ft_atoi("-42"));
	printf("'   +4210' : %d\n", ft_atoi("   +4210"));
	printf("'   +-+4210' : %d\n", ft_atoi("   +-+4210"));
	printf("'m   +-+4210' : %d\n", ft_atoi("m   +-+4210"));
	printf("'   42m10' : %d\n", ft_atoi("   42m10"));
	printf("'m' : %d\n", ft_atoi("m"));
	printf("\n*************** ATOI ***************\n");
	printf("\n'42' : %d\n", atoi("42"));
	printf("'-42' : %d\n", atoi("-42"));
	printf("'   +4210' : %d\n", atoi("   +4210"));
	printf("'   +-+4210' : %d\n", atoi("   +-+4210"));
	printf("'m   +-+4210' : %d\n", atoi("m   +-+4210"));
	printf("'   42m10' : %d\n", atoi("   42m10"));
	printf("'m' : %d\n", atoi("m"));
	printf("\n************************************\n\n");
}*/
