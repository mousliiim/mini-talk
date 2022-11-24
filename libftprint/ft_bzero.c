/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:15:07 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:25:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * La fonction bzero met a 0 ('\0') les n (taille en parametre) -> 
 * 1ers octets du bloc pointe par *s
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
 * CODE DETAILLE
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
 *
*/

/*
int	main(void)
{
	char	un[10] = "Hello!";
	char	deux[10] = "Hello!";

	printf("\nDisplay above Bzero : %s\n", un);
	ft_bzero(un, 1);
	printf("Display after Bzero : %s\n", un);
	printf("________________\n\n");
	printf("Display above Ft_Bzero : %s\n", deux);
	ft_bzero(deux, 1);
	printf("Display after Ft_Bzero : %s\n\n", deux);
	return (0);
}
*/
