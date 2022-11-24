/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:54:15 by mmourdal          #+#    #+#             */
/*   Updated: 2022/11/10 23:26:25 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * Cette fonction permet de remplir une zone mémoire, identifiée par son adresse
 * (*s) et sa taille, avec une valeur précise (c) et en indiquant le nombre 
 * d'octet a initialiser (n)
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	int	array[] = { 5, 4, 3, 2, 1 };
	char array2[] = { 'm', 'o', 'u', 's', 'l', 'i', 'm'};
	int	i;
	i = 0;
	printf("\n****** FIRST ARRAY BEFORE MEMSET ******\n");
	while (i < 5)
		printf("%d ", array[i++]);
	printf("\n\n****** FIRST ARRAY AFTER MEMSET THREE '0' ******\n");
	ft_memset(array, 0, 12);
	// 12 == Size of 2 Int in Array
	i = 0;
	while (i < 5)
		printf("%d ", array[i++]);
	printf("\n");
	i = 0;
	printf("\n****** SECOND ARRAY BEFORE MEMSET ******\n");
	while (i < 7)
		printf("%c ", array2[i++]);
	printf("\n\n****** SECOND ARRAY AFTER MEMSET THREE 'm' ******\n");
	ft_memset(array2, 'm', 3);
	// 3 == Size of 3 char in Array2
	i = 0;
	while (i < 7)
		printf("%c ", array2[i++]);
	printf("\n");

}*/
